#include <dpp/dpp.h>

class DiscordUser {
public:
    DiscordUser(){};
    ~DiscordUser(){};
    void sendWebhookMessageColor(Color color){
		dpp::cluster bot(""); // normally, you put your bot token in here. But to just run a webhook its not required
	 
	    bot.on_log(dpp::utility::cout_logger());
	 
	    /* construct a webhook object using the URL you got from Discord */
	    dpp::webhook wh("https://discord.com/api/webhooks/1074555926985584690/f8xKGwxoEP3bdOE2uAl-pHwVPI4UELQxbR-hPT6qttnsiw6oUsTME8Uqb-Yt7mL9Q5sN");
	 
	 	dpp::message msg("I Just Generated this Color : " + color.getHex());
		msg.add_file("color.png", dpp::utility::read_file("colors/" + color.getHex() + ".png"));
	    /* send a message with this webhook */
	    bot.execute_webhook_sync(wh, msg);
	}

private:
};