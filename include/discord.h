#include <dpp/dpp.h>
#include "color.h"

class DiscordUser {
public:
    DiscordUser(){};
    ~DiscordUser(){};
    void sendWebhookMessageColor(const Color& color){
		dpp::cluster bot(""); // normally, you put your bot token in here. But to just run a webhook its not required
	 
	    bot.on_log(dpp::utility::cout_logger());
	 
	    /* construct a webhook object using the URL you got from Discord */
	    dpp::webhook wh("");
	 
	 	dpp::message msg("I Just Generated this Color : " + color.getHex());
		msg.add_file("color.png", dpp::utility::read_file("colors/" + color.getHex() + ".png"));
	    /* send a message with this webhook */
	    bot.execute_webhook_sync(wh, msg);
	}

private:
};