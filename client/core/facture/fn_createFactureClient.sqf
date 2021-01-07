
private _emetteur = ctrlText 05012044;
private _details = ctrlText 05012045;
private _price =  parseNumber(ctrlText 05012047);
private _pl = lbData[05012046,(lbCurSel 05012046)];
if ((lbCurSel 05012046) isEqualTo -1) exitWith {hint localize "STR_NOTF_didNotSelectPlayer";};
_pl = call compile format ["%1", _pl];
if (isNull _pl || isNil "_pl") exitWith {hint "Sélectionner une personne"};
if (_emetteur isEqualTo "") exitWith {hint "Merci de spécifier un émetteur"};
if ((count _details) <= 0) exitWith {hint parseText "Merci de spécififer un détails de facture";};
if (_price < 0) exitWith {hint 'Vérifier votre prix'};
[1, format["Vous venez de recevoir une facture de %1€, de %2", _emetteur] remoteExec ["life_fnc_broadcast", _pl];
[(getPlayerUID player), (getPlayerUID _pl), _details, _emetteur, _price, (name player), (name _pl)] remoteExec ["fac_serv_fnc_createFacture",2];
closeDialog 0;
hint 'Facture émise avec success';



