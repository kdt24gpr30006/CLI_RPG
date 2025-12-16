#pragma once
#include <vector>
#include <memory>
#include "../../Chara/Base/CharaBase.h"
#include "../../Chara/CharaFactory/CharaFactory.hpp"
#include "../../Chara/CharaFactory/CharaType.hpp"

class EnemySpawner
{
public:

#if true
	/// <summary>
	/// éwíËÇ≥ÇÍÇΩäKëwÇ…äÓÇ√Ç¢ÇƒìGÉLÉÉÉâÉNÉ^Å[Ç™ê∂ê¨Ç≥ÇÍÇÈ
	/// </summary>
	/// <param name="floor">åªç›ÇÃäKëw</param>
	/// <returns>ê∂ê¨Ç≥ÇÍÇΩìG</returns>
	static std::unique_ptr<CharaBase> SpawnEnemiesForFloor(int floor)
	{
		std::unique_ptr<CharaBase> enemies;

		CharaFactory factory;

		switch (floor) {
		case 1:
			enemies = factory.CreateChara(CharaType::SLIME);
			break;
		case 2:
			enemies = factory.CreateChara(CharaType::SLIME);
			break;
		case 3:
			enemies = factory.CreateChara(CharaType::SLIME);
			break;
		case 4:
			enemies = factory.CreateChara(CharaType::GOBLIN);
			break;
		case 5:
			enemies = factory.CreateChara(CharaType::GOBLIN);
			break;
		case 6:
			enemies = factory.CreateChara(CharaType::GOBLIN);
			break;
		case 7:
			enemies = factory.CreateChara(CharaType::GOLEM);
			break;
		case 8:
			enemies = factory.CreateChara(CharaType::GOLEM);
			break;
		case 9:
			enemies = factory.CreateChara(CharaType::GOLEM);
			break;
		case 10:
			enemies = factory.CreateChara(CharaType::DRAGON);
			break;
		default:
			break;
		}

		return enemies;


#else ////// ï°êîÇÃìKópÅ@vectorÇ≈ï‘Ç∑


	static std::vector <std::unique_ptr<CharaBase>> SpawnEnemiesForFloor(int floor)
	{
		std::vector<std::unique_ptr<CharaBase>> enemies;

		CharaFactory factory;

		switch (floor) {
		case 1:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 2:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 3:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 4:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 5:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 6:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 7:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 8:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 9:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		case 10:
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			enemies.push_back(factory.CreateChara(CharaType::SLIME));
			break;
		default:
			break;
		}

		return enemies;

#endif
	}
};

