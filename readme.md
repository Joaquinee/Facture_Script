# Script Facture Pour Serveur Altis Life

Script Facture Pour serveur Altis Life

## Installation Client



Tout en bas du fichier function.hpp ajoutez :
```hpp
class Facture { 
  tag = "fac"; 
  class Factures { 
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
```

Dans le fichier **dialog\MasterHandler.hpp** Ajoutez : 

```hpp
#include "facture.hpp"
```
Dans le fichier CfgRemoteExec.hpp ajoutez au dessus de F(life_fnc_AAN,CLIENT) : 
```hpp
F(fac_serv_fnc_getFacture,SERVER) F(fac_serv_fnc_updateFacture,SERVER)
F(fac_serv_fnc_createFacture,SERVER) F(fac_serv_fnc_updateBanque, SERVER)
F(fac_fnc_receivedEmit,CLIENT) F(fac_fnc_loadDialog,CLIENT)
``` 
Pour finir direction dialog\player_inv.hpp et ajoutez en  dessous de : 
```hpp
class ButtonCell: Life_RscButtonMenu { 
      idc = 2014; 
      text = "$STR_PM_CellPhone"; 
      onButtonClick = "createDialog ""Life_cell_phone"";"; 
      x = 0.42 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH)); 
      y = 0.8 - (1 / 25); 
      w = (6.25 / 40); 
      h = (1 / 25); 
};
```
Ce code la : 
```hpp
class ButtonFacture: Life_RscButtonMenu { 
      idc = -1; 
      text = "Facture"; 
      onButtonClick = "closeDialog 0; createDialog ""facture"";"; 
      x = 0.1 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH)); 
      y = 0.805; 
      w = (6.25 / 40); 
      h = (1 / 25); 
};
```


## Installation Serveur 

Glisser le contenu du dossier server dans le life_server

Puis dans le fichier config.cpp ajoutez au dessus de class MySQL_Database : 

```hpp 
class Facture { 
    tag = "fac_serv"; 
    class Factures { 
        file = "\life_server\Functions\Facture"; 
        class updateFacture;
        class getFacture; 
        class createFacture; 
        class updateBanque; 
    };
};
```

## Rendu en vidéo

https://youtu.be/zgyolDdpwcA
