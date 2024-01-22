#include <dpp/dpp.h>

std::string TOKEN = "Your_API_TOKEN";
int main(){

    dpp::cluster bot(TOKEN, dpp::i_default_intents | dpp::i_message_content);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t &event){
        if(event.command.get_command_name()=="ping"){
            event.reply("Pong!");
        }else if(event.command.get_command_name() == "name")
            event.reply(event.command.usr.username);
    });

    bot.on_message_create([&bot] (const dpp::message_create_t &event){
        if(event.msg.content == "!create"){
            dpp::message msg(event.msg.channel_id, "creating Your color palatte");
            dpp::message msg1(event.msg.channel_id,"");
            system("./cpalatte");
            msg1.add_file("color_palatte.png", dpp::utility::read_file("./colorpalatte/color_palette.png"));
            bot.message_create(msg1);
        }
    });

    bot.on_ready([&bot](const dpp::ready_t &event){
        if(dpp::run_once <struct register_bot_commands>()){
            bot.global_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("name", "Your name", bot.me.id)
            );
        }
    });
    bot.start(dpp::st_wait);
    return 0;
}
