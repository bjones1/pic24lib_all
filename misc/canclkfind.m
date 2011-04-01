function canclkfind
minErr = 1e3;
bestFosc = 0;
desiredBaud = 115200;
desiredCan = 125000;
for fosc=70e6:0.001e6:80e6
    err = mean([uartErr(fosc) canErr(fosc)]);
    if err < minErr
        minErr = err;
        bestFosc = fosc;
    end
end
fprintf('\nBest match: Fosc = %f\nUART divisor = %f, error = %f\nCAN divisor = %f, error = %f\n', ...
    bestFosc, uartDiv(bestFosc), uartErr(bestFosc), canDiv(bestFosc), ...
    canErr(bestFosc));

    % Determine UART divisor in 4x mode (8x Fosc)
    function uartErr = uartErr(fosc)
        div = uartDiv(fosc);
        if (div > 65535), uartErr = 1e6; else uartErr = mod(div, 1); end
    end

    function div = uartDiv(fosc)
        div = fosc/(8*desiredBaud);
    end

    function canErr = canErr(fosc)
        div = canDiv(fosc);
        if (div > 64*8), canErr = 1e6; else canErr = mod(div, 1); end
    end

    function div = canDiv(fosc)
        div = fosc/(2*desiredCan);
    end
end
