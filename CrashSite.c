/*
  Spawns helicopter crash sites on server restart.
*/

class CrashSite {

  protected int MAIN_ITEM_AMOUNT = 10;
  protected int MISC_ITEM_AMOUNT = 15;

  ref array<vector> m_crashSites = {
    "12856.1 6.59166 9064.85",
    "12524.4 11.7239 8949.71",
    "12370.2 21.9692 9355.82",
    "5738.98 316.979 8362.11",
    "5523.39 323.301 8578.56",
    "10401.9 6.00843 2429.99",
    "12392.9 150.4 12766.4",
    "4468.57 342.419 10425.4",
  };

  protected ref TStringArray m_wrecks = {
    "Wreck_Mi8",
    "Wreck_UH1Y",
  };

  protected ref TStringArray m_mainItems = {
    "AKM", 
    "M4A1", 
    "Izh18", 
    "MP5K", 
    "UMP45", 
    "mosin9130",
    "mosin9130_black",
		"mosin9130_green",
    "mosin9130_camo",
    "AliceBag_Camo",
    "AliceBag_Green",
    "GhillieBushrag_Mossy",
    "GhillieSuit_Mossy",
    "M65Jacket_Black",
    "USMCJacket_Woodland",
    "USMCPants_Woodland",
    "CombatKnife",
    "SVD",
    "FNX45",
  };

  protected ref TStringArray m_misc = {
    "ammo_45acp", 
    "ammo_308win", 
    "ammo_9x19", 
    "ammo_380", 
    "ammo_556x45", 
    "ammo_762x54", 
    "ammo_762x54tracer", 
    "ammo_762x39", 
    "ammo_9x39", 
    "ammo_22", 
    "ammo_12gapellets",
		"mag_cmag_10rnd",
		"mag_cmag_30rnd", 
    "mag_cmag_30rnd_black",
    "mag_cmag_30rnd_green", 
    "mag_cmag_40rnd", 
    "mag_cmag_40rnd_black", 
    "mag_cmag_40rnd_green",
    "MP5_PlasticHndgrd",
    "PUScopeOptic",
    "PSO1Optic",
    "M68Optic",
    "AK_Woodbttstck",
    "M4_PlasticHndgrd",
    "M4_MPBttstck",
    "M4_T3NRDSOptic",
    "M4_Suppressor",
  };

  int framesPassed = 0;
  bool shouldSpawn = true;

  void PollCrashSite() {
    if (framesPassed < (600 / 0.1)) {
      framesPassed++;
    } else {
      if (shouldSpawn) {
        shouldSpawn = false;
        SpawnLootOnCrashSites();
        framesPassed = 0;
      }
    }
  }

  void SpawnCrashSites() {
    for (int i = 0; i < m_crashSites.Count(); i++) {
      vector pos = m_crashSites.Get(i);
      GetGame().CreateObject(m_wrecks[1], pos, false, true);
      Print("Spawning crashsite at " + pos);
    }
  }

  void SpawnLootOnCrashSites() {
    for (int i = 0; i < m_crashSites.Count(); i++) {
      vector pos = m_crashSites.Get(i);
      Print("Spawning loot for crashsite at " + pos);
      for (int j = 0; j < MAIN_ITEM_AMOUNT; j++) {
        float randX = Math.RandomFloat(0, 360);
        float randZ = Math.RandomFloat(0, 360);
        GetGame().CreateObject(m_mainItems.GetRandomElement(), pos + Vector(4.0 * Math.Sin(randX), -3.5, (8.0 * Math.Cos(randZ))), false, true);
      }
      for (int k = 0; k < MISC_ITEM_AMOUNT; k++) {
        randX = Math.RandomFloat(0, 360);
        randZ = Math.RandomFloat(0, 360);
        GetGame().CreateObject(m_misc.GetRandomElement(), pos + Vector(4.0 * Math.Sin(randX), -3.5, (8.0 * Math.Cos(randZ))), false, true);
      }
    }
  }
};