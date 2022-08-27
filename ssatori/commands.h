#define CMDNUM 3
static const UI8* cmdlist[CMDNUM] = {
	"ping",
	"clear",
	"help",
	"logout",
	"chuser",
	"chhost",
	"passwd"
};
static const UI8* cmdhelp[CMDNUM] = {
	"Response with pong",
	"Clear screen",
	"Print this help menu",
	"Logout",
	"Change username",
	"Change hostname",
	"Change password"
};


UI0 SSCommandNotFound() {
	putstr_attr("SSatori: ",RED,DEF_BG);
	putstr_attr(cmd,MAGENTA,DEF_BG);
	putstr_attr(": Command not found\n",RED,DEF_BG);
}

UI32 SSCheckCommand() {
	if (cmd[0]==0x00)
		return 0;

	if (!strcmp(cmd,"ping")) {
		putstr("pong\n");
	}

	else if (!strcmp(cmd,"clear")) {
		SSClear();
	}

	else if (!strcmp(cmd,"help")) {
		SSHelp();
	}

	else if (!strcmp(cmd,"scroll")) {
		SSScroll();
	}
	
	else if (!strcmp(cmd,"testinput")) {
		UI8 test[255];
		SSGetStr(test);
		putstr(test);
		newline();
	}

	else if (!strcmp(cmd,"logout")) SSLogout();
	else if (!strcmp(cmd,"chuser")) {
		putstr("Enter new username: ");
		SSGetStr(houriuser.username);
	}
	else if (!strcmp(cmd,"chhost")) {
		putstr("Enter new hostname: ");
		SSGetStr(houriuser.hostname);
	}
	else if (!strcmp(cmd,"passwd")) {
		putstr("Enter new password: ");
		SSGetStr(houriuser.passwd);
	}

	else
		SSCommandNotFound();

}

