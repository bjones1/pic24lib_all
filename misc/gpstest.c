#include "pic24_all.h"
#include <stdio.h>
#include <math.h>

typedef struct _COORD {
  double deg_lat;  //decimal degrees
  double deg_lon; //decimal degrees
  double lat;     //radians
  double lon;    //radians
} COORD;

COORD start;
COORD dest;

#define PI   3.141592653589793238462643383279


double to_rad(double x) {

  return (x * PI/180);
}

float haversine (COORD p1, COORD p2) {

  float R = 6371;

  float dlat;
  float dlon;
  float a,c,d;

  dlat = p2.lat - p1.lat;
  dlon = p2.lon - p1.lon;
  a = sin(dlat/2) * sin(dlat/2);
  a += cos(p1.lat)*cos(p2.lat)*sin(dlon/2)*sin(dlon/2);
  c = 2 * atan2(sqrt(a), sqrt(1.0-a));
  d = R *c;
  return(d*1000.0);
}


double approximate_distance (COORD p1, COORD p2) {

  double t1,t2,t3,t4,t5, rad_dist;
  double meters;
  double x,y;

  printf("In approximate\n");
  t1 = sin(p1.lat) * sin(p2.lat);
  t2 = cos(p1.lat) * cos(p2.lat);
  t3 = cos(p1.lon - p2.lon);
  t4 = t2 * t3;
  t5 = t1 + t4;
  printf("t1: %e,t2: %e,t3: %e,t4: %e,t5: %e \n",
         t1,t2,t3,t4,t5);


  //rad_dist = atan(-t5/sqrt(-t5 * t5 +1)) + 2 * atan(1);
  y = -t5 * t5 +1;
  x = -t5/sqrt((double)y) ;

  rad_dist = atan(x) + 2 * atan(1);


  meters = rad_dist * 3437.74677 * 1.1508 * 1.6093470878864446 * 1000;
  printf("y: %e, x: %e, rad_dist: %e, meters: %10.6f \n",
         y,x, rad_dist,meters);

  return (meters);
}

/* calculate the distance between p1, p2 */

double accurate_distance (COORD p1, COORD p2) {

  double a = 6378137;
  double b = 6356752.3142;
  double f;  // WGS-84 ellipsiod
  double L;
  double U1;
  double U2;
  double sinU1,cosU1;
  double sinU2, cosU2;
  double lambda, lambdaP;
  int iterLimit = 20;

  double sinLambda,cosLambda;
  double sinSigma;
  double cosSigma;
  double sigma;
  double sinAlpha;
  double cosSqAlpha;
  double cos2SigmaM;
  double C;

  double uSq;
  double A;
  double B;
  double deltaSigma;
  double s;
  int i;

  f = 1/298.257223563;
  L = p2.lon - p1.lon;
  U1 = atan((1-f) * tan(p1.lat));
  U2 = atan((1-f) * tan(p2.lat));
  sinU1 = sin(U1);
  cosU1 = cos(U1);
  sinU2 = sin(U2);
  cosU2 = cos(U2);
  lambda = L;
  lambdaP = 2*PI;
  i = 0;


  while (fabs(lambda-lambdaP) > 1e-12 && --iterLimit>0) {
    i++;
    sinLambda = sin(lambda);
    cosLambda = cos(lambda);
    sinSigma = sqrt((cosU2*sinLambda) * (cosU2*sinLambda) +
                    (cosU1*sinU2-sinU1*cosU2*cosLambda) *
                    (cosU1*sinU2-sinU1*cosU2*cosLambda));
    if (sinSigma==0) return 0;  // co-incident points
    cosSigma = sinU1*sinU2 + cosU1*cosU2*cosLambda;
    sigma = atan2(sinSigma, cosSigma);
    sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma;
    cosSqAlpha = 1 - sinAlpha*sinAlpha;
    cos2SigmaM = cosSigma - 2*sinU1*sinU2/cosSqAlpha;
    //if (isnan(cos2SigmaM)) cos2SigmaM = 0;  // equatorial line: cosSqAlpha=0 ('6)
    double C = f/16*cosSqAlpha*(4+f*(4-3*cosSqAlpha));
    lambdaP = lambda;
    lambda = L + (1-C) * f * sinAlpha *
             (sigma + C*sinSigma*(cos2SigmaM+C*cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)));
  }

  if (iterLimit==0) {
    printf("Failed to converge!\n");
    //return(nan(""));  // formula failed to converge, return not a number
    return(0.0);
  }

  uSq = cosSqAlpha * (a*a - b*b) / (b*b);
  A = 1 + uSq/16384*(4096+uSq*(-768+uSq*(320-175*uSq)));
  B = uSq/1024 * (256+uSq*(-128+uSq*(74-47*uSq)));
  deltaSigma = B*sinSigma*(cos2SigmaM+B/4*(cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)-
                           B/6*cos2SigmaM*(-3+4*sinSigma*sinSigma)*(-3+4*cos2SigmaM*cos2SigmaM)));
  s = b*A*(sigma-deltaSigma);

  //s = s.toFixed(3); // round to 1mm precision
  printf("Took %d iterations in accurate iteration loop\n",i);
  return s;
}



/**
"Reset" program which tests some of the ways that a PIC24 can
be reset, as well as sleep mode, idle mode, and the watchdog timer.
Intended to be used in a laboratory exercise in which the current
draw of the processor is monitored before/after the power down
modes.
*/

//persistent variables are not touched at reset
uint8_t u8_resetCount __attribute__((persistent));


int main(void) {

  double a_dist, x_dist ;
  double diff;

  configClock();                //clock configuration
  configHeartbeat();            //heartbeat LED
  configUART(DEFAULT_BAUDRATE); //serial port config
  outString(HELLO_MSG);         //say Hello!

  //  start.deg_lat = 33.271165; start.deg_lon = 88.471434;
  //  dest.deg_lat = 33.271165; dest.deg_lon = 88.47145;
  // answer, gcc double:
  //In Meters,  Accurate: 1.490661, Approximate: 1.488028, percent diff:   0.18%


  start.deg_lat = 33.2714;
  start.deg_lon = 88.4717;
  dest.deg_lat = 33.2711;
  dest.deg_lon = 88.4714;
  // answer gcc double:
  // In Meters,  Accurate: 43.454266, Approximate: 43.453377, percent diff:   0.00%
  // answer dsPIC30, 64-bit doubles
  ///In Meters, Accurate: 43.454266, Approaximate: 43.453274


  start.lat = to_rad(start.deg_lat);
  start.lon = to_rad(start.deg_lon);

  dest.lat = to_rad(dest.deg_lat);
  dest.lon = to_rad(dest.deg_lon);

  a_dist = accurate_distance (start,dest);
  x_dist = approximate_distance (start,dest);


  diff= (a_dist-x_dist)/a_dist * 100.0;

  printf("Distance between lat %10.6f, lon %10.6f, and lat %10.6f, lon %10.6f :\n",
         start.deg_lat, start.deg_lon, dest.deg_lat, dest.deg_lon);
  printf("In Meters,  Accurate: %f, Approximate: %f, percent diff: %6.2f%%\n",
         a_dist, x_dist, diff);


  x_dist = haversine (start,dest);

  diff= (a_dist-x_dist)/a_dist * 100.0;

  printf("Distance between lat %10.6f, lon %10.6f, and lat %10.6f, lon %10.6f :\n",
         start.deg_lat, start.deg_lon, dest.deg_lat, dest.deg_lon);
  printf("In Meters,  Accurate: %f, Haversine: %f, percent diff: %6.2f%%\n",
         a_dist, x_dist, diff);


  while (1) {

  } // end while (1)
  return 0;
}
