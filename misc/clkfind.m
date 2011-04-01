clc
% Desired Fosc frequency
des = 80e6;
% Maximum error allowed
err = 0.001e6;
for oscTune = -32:31
    Frc = 7.37e6 * (1 + 0.00375*oscTune);
    for pre=2:33
        Fref = Frc/pre;
        if ( (Fref < 0.8e6) || (Fref > 8e6) )
            continue;
        end
        for m=1:512
            Fvco = Fref*m;
            if ( (Fvco < 100e6) || (Fvco > 200e6) )
                continue;
            end
            for post=[2 4 8]
                Fosc = Fvco/post;
                if (Fosc > 80e6+err)
                    continue;
                end
                newErr = abs(Fosc - des);
                if (newErr <= err)
                    disp([oscTune Frc/1e6 pre Fref/1e6 m Fvco/1e6 post Fosc/1e6]);
%                    err = newErr;
                end
            end
        end
    end
end