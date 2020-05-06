// Keep this lines for a best effort IntelliSense of Visual Studio 2017.
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\Lib\jquery.d.ts" />
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\TcHmi.d.ts" />
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\Controls\System\TcHmiControl\Source.d.ts" />

// Keep this lines for a best effort IntelliSense of Visual Studio 2013/2015.
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\Lib\jquery\jquery.js" />
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\TcHmi.js" />

(function (TcHmi) {

    var EnumTPAToString = function (par1) {
        //console.log(par1);
        switch (par1) {
            case 0:
                return 'startet';

            case 1:
                return 'gestartet';

            case 2:
                return 'stoppt';

            case 3:
                return 'gestoppt';

            default:
                return 'Unknown state: ' + par1;
        }
    };
    
    TcHmi.Functions.registerFunction('EnumTPAToString', EnumTPAToString);
})(TcHmi);