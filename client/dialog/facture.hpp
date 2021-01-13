class RscListBox
{
    style = 16;
    idc = -1;
    type = 5;
    w = 0.275;
    h = 0.04;
    font = "RobotoCondensed";
    colorSelect[] = {1, 1, 1, 1};
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0.28,0.28,0.28,0.28};
    colorSelect2[] = {1, 1, 1, 0.2};
    colorSelectBackground[] = {0.28,0.28,0.28,0.28};
    colorSelectBackground2[] = {0.28,0.28,0.28,0.28};
    colorScrollbar[] = {0.2, 0.2, 0.2, 1};
    colorPicture[] = {1, 1, 1, 0.2};
    colorPictureSelected[] = {1, 1, 1, 0.2};
    colorPictureDisabled[] = {1, 1, 1, 0.2};
    arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
    arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
    wholeHeight = 0.45;
    rowHeight = 0.04;
    color[] = {0.7, 0.7, 0.7, 1};
    colorActive[] = {1, 1, 1, 0.2};
    colorDisabled[] = {1, 1, 1, 0.2};
    sizeEx = 0.023;
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    soundCollapse[] = {"",0.1,1};
    maxHistoryDelay = 1;
    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
    class ListScrollBar: Life_RscScrollBar
    {
        color[] = {1,1,1,1};
        autoScrollEnabled = 1;
    };
};

class RscEdit
{
	deletable=0;
	fade=0;
	access=0;
	type=2;
	colorBackground[] = {0, 0, 0, 0.6};
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    colorText[] = {0.95, 0.95, 0.95, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
	colorSelection[] = {0,0.48,1,.6};
	autocomplete="";
	text="";
	size=0.2;
	style = "16 + 512";
	font="RobotoCondensedLight";
	shadow=0;
	sizeEx = "(((pixelh * 7) * ((getResolution select 1) / 1080)) * 4)";
	canModify=1;
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.65};
};





class facture {
    idd = 040116;
    name= "facture";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[[040116, 040117], 0] spawn A3URL_fnc_init";
    class controlsBackground {
		 class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.6 - (22 / 250);
        };
        
    };
    class controls {
		class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 040121;
            text = "Liste des facture en attente ";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };  
		 class ButtonMyHistorique: Life_RscButtonMenu
		{
			idc = -1;
			text = "Historique";
			onButtonClick = "closeDialog 0;createDialog ""facture_historique"";";
			x = 0.1;
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ButtonCloseDialog: Life_RscButtonMenu
		{
			idc = -1;
			onButtonClick = "closeDialog 0;";
			text = "XX";
			x = 0.875;
			y = 0.2;
			w = 0.025;
			h = 0.04 ;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class ButtonCreateFacture: Life_RscButtonMenu
		{
			idc = -1;
			text = "Crée";
			x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
			onButtonClick = "closeDialog 0;createDialog ""facture_create"";";
		};

		class ButtonPay: Life_RscButtonMenu
		{
			idc = 040119;
			text = "Payer";
			x = 0.26 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.02,0.451,0.063,1};
			show = false;
		};
		class ButtonRefuse: Life_RscButtonMenu
		{
			idc = 040120;
			text = "Refuser";
			x = 0.42 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.541,0,0,1};
			show = false;
		};
		class listBox: RscListBox
		{
			idc = 040117;
			sizeEx = 0.04;
			x = 0.1125;
			y = 0.31994;
			w = 0.275;
			h = 0.42;
			onLBSelChanged = "[(_this # 0),(_this # 1),0, 040118] spawn A3URL_fnc_onLbSelChanged";

		};
		class RscEdit_1400: RscEdit
		{
			idc = -1;
			x = 0.1125;
			y = 0.26;
			w = 0.274065;
			h = 0.0399945;
			text = "";
			onKeyUp = "[(_this # 0), 040117, 040118] spawn A3URL_fnc_searchListbox";
		};

		class Text_Menu: Life_RscControlsGroup {
			idc = -1;
			x = 0.4125;
			y = 0.26;
			w = 0.475;
			h = 0.48;
			class controls {
				class RscStructureText_Information: Life_RscStructuredText {
					idc = 040118;
					text = "";
					x = 0;
					y = 0;
					w = 0.475;
					h = 0.48;
				};
			};
		};
    };
};
class facture_historique {
    idd = 04011838;
    name= "facture_historique";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[[04011838, 04011839], 1] spawn A3URL_fnc_init";
    class controlsBackground {
		 class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.6 - (22 / 250);
        };
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "Historique des factures reçu";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };  
    };
    class controls {
		 class ButtonMyHistorique: Life_RscButtonMenu
		{
			idc = -1;
			text = "Emise";
			onButtonClick = "closeDialog 0; createDialog ""facture_emis"";";
			x = 0.1;
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ButtonCloseDialog: Life_RscButtonMenu
		{
			idc = -1;
			onButtonClick = "closeDialog 0;";
			text = "XX";
			x = 0.875;
			y = 0.2;
			w = 0.025;
			h = 0.04 ;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};

		class listBox: RscListBox
		{
			idc = 04011839;
			sizeEx = 0.04;
			x = 0.1125;
			y = 0.31994;
			w = 0.275;
			h = 0.42;
			onLBSelChanged = "[(_this # 0),(_this # 1),1,04011840 ] spawn A3URL_fnc_onLbSelChanged";

		};

		class Text_Menu: Life_RscControlsGroup {
			idc = -1;
			x = 0.4125;
			y = 0.26;
			w = 0.475;
			h = 0.48;
			class controls {
				class RscStructureText_Information: Life_RscStructuredText {
					idc = 04011840;
					text = "";
					x = 0;
					y = 0;
					w = 0.475;
					h = 0.48;
				};
			};
		};

		class RscEdit_1400: RscEdit
		{
			idc = -1;
			x = 0.1125;
			y = 0.26;
			w = 0.274065;
			h = 0.0399945;
			text = "";
			onKeyUp = "[(_this # 0), 04011839, 04011840] spawn A3URL_fnc_searchListbox";
		};
    };
};
class facture_emis {
    idd = 05012014;
    name= "facture_emis";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[[05012014, 05012015], 2] spawn A3URL_fnc_init";
    class controlsBackground {
		 class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.6 - (22 / 250);
        };
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "Historique des factures émis";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };  
    };
    class controls {
		class ButtonCloseDialog: Life_RscButtonMenu
		{
			idc = -1;
			onButtonClick = "closeDialog 0;";
			text = "XX";
			x = 0.875;
			y = 0.2;
			w = 0.025;
			h = 0.04 ;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};

		class listBox_emis: RscListBox
		{
			idc = 05012015;
			sizeEx = 0.04;
			x = 0.1125;
			y = 0.31994;
			w = 0.275;
			h = 0.42;
			onLBSelChanged = "[(_this # 0),(_this # 1),2, 05012016] spawn A3URL_fnc_onLbSelChanged";

		};
		class Text_Menu: Life_RscControlsGroup {
			idc = -1;
			x = 0.4125;
			y = 0.26;
			w = 0.475;
			h = 0.48;
			class controls {
				class RscStructureText_Information: Life_RscStructuredText {
					idc = 05012016;
					text = "";
					x = 0;
					y = 0;
					w = 0.475;
					h = 0.48;
				};
			};
		};

		class RscEdit_1400: RscEdit
		{
			idc = -1;
			x = 0.1125;
			y = 0.26;
			w = 0.274065;
			h = 0.0399945;
			text = "";
			onKeyUp = "[(_this # 0), 05012015, 05012016] spawn A3URL_fnc_searchListbox";
		};
    };
};


class facture_create {
    idd = 05012043;
    name= "facture_create";
    movingEnable = 0;
    enableSimulation = 1;
	onLoad = "[[05012043, 05012046], 3] spawn A3URL_fnc_init";
    class controlsBackground {
		 class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.6 - (22 / 250);
        };
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "Historique des factures émis";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };  
    };
    class controls {
		class ButtonCloseDialog: Life_RscButtonMenu
		{
			idc = -1;
			onButtonClick = "closeDialog 0;";
			text = "XX";
			x = 0.875;
			y = 0.2;
			w = 0.025;
			h = 0.04 ;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};

		class RscText_1004: Life_RscText
		{
			idc = -1;
			text = "Nom de l'émeutteur : "; //--- ToDo: Localize;
			x = 0.105;
			y = 0.28;
			w = 0.3875;
			h = 0.04;
		};
		class RscText_1005: Life_RscText
		{
			idc = 1005;
			text = "Details de la facture"; //--- ToDo: Localize;
			x = 0.105001;
			y = 0.399999;
			w = 0.3875;
			h = 0.0399999;
		};
		class edit_Emesseur: RscEdit
		{
			idc = 05012044;
			x = 0.1125;
			y = 0.34;
			w = 0.319743;
			h = 0.0399945;
		};
		class RscEdit_1401: RscEdit
		{
			idc = 05012045;
			x = 0.1125;
			y = 0.46;
			w = 0.319743;
			h = 0.259964;
		};
		class RscButtonMenu_2400: Life_RscButtonMenu
		{
			idc = -1;
			text = "Envoyer"; //--- ToDo: Localize;
			onButtonClick = "[] spawn A3URL_fnc_createFactureClient;";
			x = 0.42 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
		};
		class RscText_1007: Life_RscText
		{
			idc = 1007;
			text = "Recepteur : "; //--- ToDo: Localize;
			x = 0.475;
			y = 0.28;
			w = 0.4125;
			h = 0.04;
		};
		class RscCombo_2100: Life_RscCombo
		{
			idc = 05012046;
			x = 0.4775;
			y = 0.336;
			w = 0.4;
			h = 0.04;
		};
		class RscText_1008: Life_RscText
		{
			idc = 1008;
			text = "Prix en €"; //--- ToDo: Localize;
			x = 0.475;
			y = 0.4;
			w = 0.4;
			h = 0.04;
		};
		class RscEdit_1402: RscEdit
		{
			idc = 05012047;
			text = "";
			x = 0.4875;
			y = 0.46;
			w = 0.3875;
			h = 0.04;
		};
    };
};



		




		
		
