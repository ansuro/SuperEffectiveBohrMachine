// Keep this lines for a best effort IntelliSense of Visual Studio 2017.
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\Lib\jquery.d.ts" />
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\TcHmi.d.ts" />
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\Controls\System\TcHmiControl\Source.d.ts" />

// Keep this lines for a best effort IntelliSense of Visual Studio 2013/2015.
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\Lib\jquery\jquery.js" />
/// <reference path="D:\TwinCAT\Functions\TE2000-HMI-Engineering\Infrastructure\TcHmiFramework\Latest\TcHmi.js" />

(function (TcHmi) {

    var EnumTPBToString = function (par1) {
        switch (par1) {
            case 0:
                return 'synchronsierend';

            case 1:
                return 'synchronisiert';

            case 2:
                return 'anhaltend';

            case 3:
                return 'angehalten';

            default:
                return 'Unknown state: ' + par1;
        }
    };
    
    TcHmi.Functions.registerFunction('EnumTPBToString', EnumTPBToString);
})(TcHmi);