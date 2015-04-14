#include <znc/main.h>
#include <znc/Client.h>
#include <znc/Chan.h>
#include <znc/User.h>
#include <znc/Modules.h>

class CDropBearMod: public CModule {
public:
	
	MODCONSTRUCTOR(CDropBearMod) {}

	bool OnLoad(const CString& sArgs, CString& sMessage) override {
		args = sArgs;
		return true;
	}

	EModRet OnUserMsg(CString& starget, CString& sMessage) override {
		PutIRC("PRIVMSG " + args + " :" + starget + ": "+ sMessage);
		return HALT;
	}
private:
	CString args = "";
};

template<> void TModInfo<CDropBearMod>(CModInfo& Info) {
	Info.AddType(CModInfo::UserModule);
	Info.SetWikiPage("DropBear");
	Info.SetHasArgs(true);
	Info.SetArgsHelpText("The channel to redirect messages to");
}

USERMODULEDEFS(CDropBearMod, "Drops things!")
