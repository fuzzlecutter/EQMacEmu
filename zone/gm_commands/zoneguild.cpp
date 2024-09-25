#include "../client.h"


void command_zoneguild(Client* c, const Seperator* sep)
{
	int arguments = sep->argnum;
	if (!arguments) {
		c->Message(Chat::Default, "Usage: #zoneguild [Zone ID|Zone Short Name] [Guild Id] [X] [Y] [Z]");
		return;
	}

	const char* zone_identifier = sep->arg[1];

	if (Strings::IsNumber(zone_identifier) && !strcmp(zone_identifier, "0")) {
		c->Message(Chat::Default, "Sending you to the safe coordinates of this zone.");

		c->MovePC(
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0,
			ZoneToSafeCoords
		);
		return;
	}

	auto zone_id = (
		sep->IsNumber(1) ?
		std::stoul(zone_identifier) :
		database.GetZoneID(zone_identifier)
		);
	auto zone_short_name = database.GetZoneName(zone_id);
	if (!zone_id || !zone_short_name) {
		c->Message(
			Chat::Default,
			fmt::format(
				"No zones were found matching '{}'.",
				zone_identifier
			).c_str()
		);
		return;
	}

	auto min_status = database.GetMinStatus(zone_id);
	if (c->Admin() < min_status) {
		c->Message(Chat::Default, "Your status is not high enough to go to this zone.");
		return;
	}


	const char* guild_identifier = sep->arg[2];

	uint32 guild_id = (uint32)(
		sep->IsNumber(2) ?
		atol(guild_identifier) :
		GUILD_NONE
		);

	if (guild_id == 0)
		guild_id = GUILD_NONE;

	auto x = sep->IsNumber(3) ? std::stof(sep->arg[3]) : 0.0f;
	auto y = sep->IsNumber(4) ? std::stof(sep->arg[4]) : 0.0f;
	auto z = sep->IsNumber(5) ? std::stof(sep->arg[5]) : 0.0f;
	auto zone_mode = sep->IsNumber(3) ? ZoneSolicited : ZoneToSafeCoords;

	c->MovePCGuildID(
		zone_id,
		guild_id,
		x,
		y,
		z,
		0.0f,
		0,
		zone_mode
	);
}