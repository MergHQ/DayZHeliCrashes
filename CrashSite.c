/*
  Spawns helicopter crash sites on server restart.
*/

class CrashSite {

  ref array<vector> m_crashSites;

  protected ref TStringArray m_wrecks = {
    "Wreck_Mi8",
    "Wreck_UH1Y",
  };

  protected ref TStringArray m_weapons = {
    "AKM", 
    "M4A1", 
    "izh18", 
    "mp5k", 
    "ump45", 
    "svd", 
    "mosin9130",
    "mosin9130_black",
		"mosin9130_green",
    "mosin9130_camo",
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
  };

  int framesPassed = 0;
  bool shouldSpawn = true;

  void CrashSite() {
    m_crashSites = new array<vector>;
  }

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

  void SpawnCrashSites(int num) {
    for (int i = 0; i < num; i++) {
      vector pos = SnapToGround("9534.84 310.333 8960.49");
      GetGame().CreateObject(m_wrecks[1], pos, false, true );
      m_crashSites.Insert(pos);
    }
  }

  void SpawnLootOnCrashSites() {
    for (int i = 0; i < m_crashSites.Count(); i++) {
      vector pos = m_crashSites.Get(i);
      for (int j = 0; j < 6; j++) {
        float randX = Math.RandomFloat(-1, 1);
        float randZ = Math.RandomFloat(-1, 1);
        Print("Spawning weapon randX " + randX);
        Print("Spawning weapon randZ " + randZ);
        GetGame().CreateObject(m_weapons.GetRandomElement(), pos + Vector(4.0 * Math.Sin(randX), -3.5, 4.0 + (8.0 * Math.Cos(randZ))), false, true);
      }
      for (int k = 0; k < 10; k++) {
        randX = Math.RandomFloat(-1, 1);
        randZ = Math.RandomFloat(-1, 1);
        Print("Spawning misc randX " + randX);
        Print("Spawning misc randZ " + randZ);
        GetGame().CreateObject(m_misc.GetRandomElement(), pos + Vector(4.0 * Math.Sin(randX), -3.5, 4.0 + (8.0 * Math.Cos(randZ))), false, true);
      }
    }
  }

  vector SnapToGround(vector pos)
  {
      float pos_x = pos[0];
      float pos_z = pos[2];
      float pos_y = GetGame().SurfaceY( pos_x, pos_z );
      vector tmp_pos = Vector( pos_x, pos_y, pos_z );
      tmp_pos[1] = tmp_pos[1] + pos[1];

      return tmp_pos;
  }
};