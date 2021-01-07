[CLIENT]
----------------------------------------------------
Glissez les fichiers présent dans le fichier `client` dans votre MpMissions
----------------------------------------------------
Ouvrez ensuite `Functions.hpp` puis ajoutez tous en bas :
class Facture {
    tag = "fac";
    class Dev {
        file = "core\facture";
        class searchListbox;
        class init;
        class onLbSelChanged;
        class payFacture;
        class refuseFacture;
        class loadDialog;
        class createFactureClient;
        class receivedEmit;
    };
};
----------------------------------------------------
Direction `dialog\MasterHandler.hpp` puis ajoutez :
`#include "facture.hpp"`
----------------------------------------------------
Direction `CfgRemoteExec.hpp` puis ajoutez au dessus de `F(life_fnc_AAN,CLIENT)` :
F(fac_serv_fnc_getFacture,SERVER)
F(fac_serv_fnc_updateFacture,SERVER)
F(fac_serv_fnc_createFacture,SERVER)
F(fac_serv_fnc_updateBanque, SERVER)
F(fac_fnc_receivedEmit,CLIENT)
F(fac_fnc_loadDialog,CLIENT)
----------------------------------------------------
Direction `dialog\player_inv.hpp` :
En-dessous de 
`
class ButtonCell: Life_RscButtonMenu {
    idc = 2014;
    text = "$STR_PM_CellPhone";
    onButtonClick = "createDialog ""Life_cell_phone"";";
    x = 0.42 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
    y = 0.8 - (1 / 25);
    w = (6.25 / 40);
    h = (1 / 25);
};
`
Ajoutez :
`
class ButtonFacture: Life_RscButtonMenu {
    idc = -1;
    text = "Facture";
    onButtonClick = "closeDialog 0; createDialog ""facture"";";
    x = 0.1 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
    y = 0.805;
    w = (6.25 / 40);
    h = (1 / 25);
};
`
----------------------------------------------------
[SERVER]
Glissez les fichiers présent dans le fichier `server` dans votre life_server
----------------------------------------------------
Ouvrez ensuite `config.cpp` puis ajoutez au dessus de `class MySQL_Database` :
class Facture {
    tag = "fac_serv";
    class Facture {
        file = "\life_server\Functions\Facture";
        class updateFacture;
        class getFacture;
        class createFacture;
        class updateBanque;
    };
};
----------------------------------------------------
[SQL]
Executer le fichier `DATA.SQL` dans votre database server