params ["_control", "_selectedIndex", "_type", "_struct"];
disableSerialization;
private _display = ctrlParent _control;
private _structured_text = _display displayCtrl _struct;
switch (_type) do {
	case 0: {
		private _data = _control lbData _selectedIndex;
		_data = call compile format ["%1", _data];
		{ctrlShow [_x, true];} forEach  [040119, 040120];
		buttonSetAction[040119, format["[%1] call fac_fnc_payFacture", _selectedIndex]];
		buttonSetAction[040120, format["[%1] call fac_fnc_refuseFacture", _selectedIndex]];
		_structured_text ctrlSetStructuredText parseText format [
		"Emetteur : %1 <br />" +
		"Le : %4<br /><br />" +
		"Détails : <br /><br />%2<br /><br />" +
		"Prix : <t color='#ff8c00' size='1' font='PuristaSemiBold'>%3€</t><br />",
		_data # 0,
		_data # 1,
		_data # 2,
		_data # 4
		];
	};
	case 1 : {
		private _data = _control lbData _selectedIndex;
		_data = call compile format ["%1", _data];
		_structured_text ctrlSetStructuredText parseText format [
		"Emetteur : %1 <br />" +
		"Le : %6<br /><br />" +
		"Détails : <br /><br />%2<br /><br />" +
		"Prix : <t color='#ff8c00' size='1' font='PuristaSemiBold'>%3€</t><br />" +
		"%4 le : %5",
		_data # 0,
		_data # 1,
		_data # 2,
		switch (_data # 4) do {case 0: {"Payer"}; case 2: {"Refuser"};},
		_data # 6,
		_data # 5
		];
	};
	case 2 : {
		private _data = _control lbData _selectedIndex;
		_data = call compile format ["%1", _data];
		_structured_text ctrlSetStructuredText parseText format [
		"Recepteur : %1 <br />" +
		"Le : %6 <br /><br />" +
		"Détails : <br /><br />%2<br /><br />" +
		"Prix : <t color='#ff8c00' size='1' font='PuristaSemiBold'>%3€</t><br />" +
		"%4  %5",
		_data # 0,
		_data # 1,
		_data # 2,
		switch (_data # 4) do {case 0: {"Payer le :"}; case 1: {"En attente"};case 2: {"Refuser le :"};},
		switch (_data # 4) do {case 1: {""}; default {_data # 6};},
		_data # 5
		];
	};
};
private _ctrlPos = ctrlPosition _structured_text;
		_ctrlPos set [3,(ctrltextheight _structured_text) min (safezoneH - (_ctrlPos select 1) + 0.13)];
		_structured_text ctrlSetPosition _ctrlPos;
		_structured_text ctrlCommit 0;