/*
  Spawns helicopter crash sites on server restart.
*/

class CrashSite {

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


  void SpawnCrashSites(int num) {
    for (int i = 0; i < num; i++) {
      vector pos = SnapToGround("9534.84 310.333 8960.49");
      GetGame().CreateObject(m_wrecks[1], pos, false, true );

      EntityAI m_AirDropLoot = EntityAI.Cast(GetGame().CreateObject("LargeTent", pos, false, true ));
      for (int j = 0; j < 5; j++) {
        m_AirDropLoot.GetInventory().CreateInInventory(m_weapons.GetRandomElement());
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