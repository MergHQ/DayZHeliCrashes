# DayZ helicopter crash sites

DayZ mod inspired crash sites for DayZ standalone

## Implementation

init.c

1. Include `CrashSite.c`
```c++
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\CrashSite\\CrashSite.c"
```

2. Create a member variable for the crashsite spawner.

```c++
class CustomMission : MissionServer
{
  ref CrashSite m_crashSiteSpawner;

  // ...
```

3. Create the instance in the OnInit method in your implementation of `MissionServer`. Spawn the crash sites.

```c++
class CustomMission : MissionServer
{
	override void OnInit()
	{
    m_crashSiteSpawner = new CrashSite();
    m_crashSiteSpawner.SpawnCrashSites();
  }

  // ...
```

4. Implement this to the OnUpdate method in your implementation of `MissionServer`.

```c++
	override void OnUpdate(float timeslice) {
		super.OnUpdate( timeslice );
		m_crashSiteSpawner.PollCrashSite();
	}
```

5. Done.

## Modifications

There are arrays of crash site positions and loot tables in the `CrashSite.c` file. You can modify those to your own liking.

## Stuff you should know

- The crash sites are *not* deleted on server restart, so the server might spawn new crash sites on top of the old ones. If you know a way to create objects without them being saved on restart, make a PR or let me know!

