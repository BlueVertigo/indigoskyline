#include "zcommon.acs"
#include "commonfuncs.h"
#library "tspacs"

global int 50:PlayerTID[];
int LastxFixed = 0;
int LastyFixed = 0;
int LastzFixed = 0;
int LastCurve = 0;
    
script "TSPPickupSounds" (int which)
{
  if(CheckInventory("PlayingPickupSound") > 0)
  {
    Terminate;
  }
  else
  {
    GiveInventory("PlayingPickupSound", 1);
    if(CheckInventory("IsMel") > 0)
    {
      if(GetPlayerInfo(PlayerNumber(), PLAYERINFO_GENDER) == 2)
      {
        switch (which)
        {
          case 1:
            LocalAmbientSound("melflavpickuprobo/Pistol",127);    
            Delay(41);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 2:
            LocalAmbientSound("melflavpickuprobo/ZekeShotgun",127);
            Delay(49);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 3:
            LocalAmbientSound("melflavpickuprobo/Crossbow",127);
            Delay(35);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 4:
            LocalAmbientSound("melflavpickuprobo/Ammobox50",127);
            Delay(123);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 5:
            LocalAmbientSound("melflavpickuprobo/RocketNailgunLauncher",127);
            Delay(67);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 6:
            Terminate;
          case 7:
            LocalAmbientSound("melflavpickuprobo/RocketLauncher1",127);
            Delay(67);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
        }
      }
      else
      {
        switch (which)
        {
          case 1:
            LocalAmbientSound("melflavpickup/Pistol",127);    
            Delay(46);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 2:
            LocalAmbientSound("melflavpickup/ZekeShotgun",127);
            Delay(60);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 3:
            LocalAmbientSound("melflavpickup/Crossbow",127);
            Delay(53);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 4:
            LocalAmbientSound("melflavpickup/Ammobox50",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 5:
            LocalAmbientSound("melflavpickup/RocketNailgunLauncher",127);
            Delay(69);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 6:
            Terminate;
          case 7:
            LocalAmbientSound("melflavpickup/RocketLauncher1",127);
            Delay(69);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
        } 
      }
    }
    else if(CheckInventory("IsVexler") > 0)
    {
      if(GetPlayerInfo(PlayerNumber(), PLAYERINFO_GENDER) == 2)
      {
        switch (which)
        {
          case 1:
            LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/Pistol",127);  Did it this way so it'd be easy to undo 
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 2:
            LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/ZekeShotgun",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 3:
            LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/Crossbow",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 4:
            LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/Ammobox50",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 5:
            LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/RocketNailgunLauncher",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 6:
            Terminate;
          case 7:
            LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/RocketNailgunLauncher",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
        } 
      }
      else
      {
        switch (which)
        {
          case 1:
            LocalAmbientSound("secretmessage",127); //"vexflavpickup/Pistol",127);  Did it this way so it'd be easy to undo 
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 2:
            LocalAmbientSound("secretmessage",127); //"vexflavpickup/ZekeShotgun",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 3:
            LocalAmbientSound("secretmessage",127); //"vexflavpickup/Crossbow",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 4:
            LocalAmbientSound("secretmessage",127); //"vexflavpickup/Ammobox50",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 5:
            LocalAmbientSound("secretmessage",127); //"vexflavpickup/RocketNailgunLauncher",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
          case 6:
            Terminate;
          case 7:
            LocalAmbientSound("secretmessage",127); //"vexflavpickup/RocketNailgunLauncher",127);
            Delay(144);
            TakeInventory("PlayingPickupSound", 1);
            Terminate;
        } 
      }
    }
    else
    {
      Terminate;
    }
  }
}

script "TSPHUDHealthNumberColor" ENTER
{
  if(GetActorProperty( 0, APROP_Health) >= 101)
  {
    GiveInventory("Over100Health",1);
    Delay(6);
    Restart;
  }
  else
  {
    TakeInventory("Over100Health",1);
    Delay(6);
    Restart;
  }
}

script "TSPIDKFAFix" ENTER
{
  if(CheckInventory("HellFireShell") >= 92)
    {
    if(CheckInventory("BuckShotShell") >= 92)
    {
      if(GetCVar("tsp_shellpool") == true)
      {
        TakeInventory("HellFireShell",96);
        TakeInventory("BuckShotShell",96);
        TakeInventory("PoisonShell",96);
        TakeInventory("ElectricShell",96);
        TakeInventory("TSPShells",96);
        GiveInventory("HellFireShell",20);
        GiveInventory("BuckShotShell",36);
        GiveInventory("PoisonShell",20);
        GiveInventory("ElectricShell",20);
        GiveInventory("TSPShells",96);
        GiveInventory("MelZekeShotgun",1);
        Delay(6);
        Restart;
      }
      else
      {
        TakeInventory("HellFireShell",96);
        TakeInventory("BuckShotShell",96);
        TakeInventory("PoisonShell",96);
        TakeInventory("ElectricShell",96);
        TakeInventory("TSPShells",96);
        GiveInventory("MelZekeShotgunNoPool",1);
        Delay(6);
        Restart;
      }
    }
      Delay(6);
      Restart;
    }
    else
    {
      Delay(6);
      Restart;
    }
}

script "TSPEnterScript1" ENTER
{

  hudmessage (s:"Blue Vertigo Presents: The Space Pirate\n \nCvars:\n \ntsp_shellpool - If set to true/1 (default), all shell types share the same ammo pool. If set to false/0, they do not and each has a separate ammo pool.
  \n\r_drawvoxels - If set to true/1 (default), voxels will be used for crossbow bolts and items. If set to true/1, models will be used for the crossbow bolts and sprites will be used for items. If you're playing this in GZDoom models will render faster, so switch if you're having performance issues, but if you're playing in ZDoom the voxels will render just fine.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_GREEN,1.5,0.375,0.1);

  TakeInventory("PlayingPickupSound", 1);
  Terminate;
}

script "TSPArmorScript" (void)
{
  if(CheckInventory("BasicArmor") >= 1)
  {
    Delay(6);
    Restart;
  }
  else
  {
    TakeInventory("TSPGreenDamageReduction",1);
    TakeInventory("TSPGreenArmorDamage",1);
    TakeInventory("TSPBlueDamageReduction",1);
    TakeInventory("TSPBlueArmorDamage",1);
    Terminate;
  }
}

script "TSPBoltStickScript" (void)
{
  int e257zsTracerNewTID = (UniqueTID());
  Thing_ChangeTID (0,e257zsTracerNewTID);
  SetActivator(0,AAPTR_TRACER);
  int e257zsTracerAngle = GetActorAngle(0);
  SetActorAngle (e257zsTracerNewTID,e257zsTracerAngle);
  Terminate;
}

script "TSPBoltHurtTracerScript" (void)
{
  SetActivator(0,AAPTR_TRACER);
  Thing_Damage2(0,Random(128,384),MOD_R_SPLASH); 
  Terminate;
}

script "TSPBoltHurtTracerScriptNoRadius" (void)
{
  SetActivator(0,AAPTR_TRACER);
  Thing_Damage2(0,Random(30,90),MOD_R_SPLASH); 
  Terminate;
}

script "GetShellPoolCVAR" (void)
{
  SetResultValue(GetCVar("tsp_shellpool"));
}

script "GetToasterCVAR" (void)
{
  SetResultValue(GetCVar("tsp_toaster"));
}

script "GetZMeleeCVAR" (void)
{
  SetResultValue(GetCVar("tsp_zmelee"));
}

script "GetBeamInfiniteCVAR" (void)
{
  SetResultValue(GetCVar("tsp_beaminf"));
}

script "GetGoldenPistolCVAR" (void)
{
  SetResultValue(GetCVar("tsp_goldenpistol"));
}

script "GetFistsStartCVAR" (void)
{
  SetResultValue(GetCVar("tsp_fistsstart"));
}

script "GetMagPushCVAR" (void)
{
  SetResultValue(GetCVar("tsp_melmagpush"));
}

script "GetActionModeCVAR" (void)
{
  SetResultValue(GetCVar("tsp_actionmode"));
}

script "GetSuperSecretCVAR" (void)
{
  SetResultValue(GetCVar("tsp_supersecret"));
}

script "TSPGetGameSkill" (void)
{
  SetResultValue(GameSkill());
}

script "TSPSetProjectilePitch" (void)
{
  SetActorPitch(0, VectorAngle (GetActorVelZ(0), sqrt(FixedMul(GetActorVelX(0),GetActorVelX(0))+FixedMul(GetActorVelY(0),GetActorVelY(0)))));
  Terminate;
}

script "TSPBeamDeath" (void)
{
  SetActorProperty(0,APROP_RenderStyle,STYLE_Add);
}

script "TSPDifficultyLoadouts" ENTER
{
  if (GameSkill() == 0) { GiveInventory("TSPEasyModePickup",1); }
  if (GameSkill() == 1) { GiveInventory("TSPNormalModePickup",1); }
  if (GameSkill() == 2) { GiveInventory("TSPNormalModePickup",1); }
  if (GameSkill() == 3) { GiveInventory("TSPNormalModePickup",1); }
  if (GameSkill() == 4) { GiveInventory("TSPDTPPickup",1); }
  if (GameSkill() == 5) { GiveInventory("TSPSurvivorModePickup",1); }
}

Script "PlayerTID" ENTER
{
  int PlayerNumberCheck = PlayerNumber();
  int NewBeamOriginTID = UniqueTID();
  int OriginTIDArrayNo = PlayerNumber() + 300;
  if(PlayerTID[PlayerNumberCheck] == 0)
  {
    int NewPlayerTID = UniqueTID();
	PlayerTID[PlayerNumberCheck] = NewPlayerTID;
    Thing_ChangeTid(0,NewPlayerTID);
  }
  else if(ActivatorTID () == 0)
  {
    Thing_ChangeTid(0,PlayerTID[PlayerNumberCheck]);
  }
  if(GetUserVariable(0,"user_beamorigintid") == 0 | PlayerTID[OriginTIDArrayNo] == 0)
  {
    PlayerTID[OriginTIDArrayNo] = NewBeamOriginTID;
    SetUserVariable(0,"user_beamorigintid",NewBeamOriginTID);
  }
}

Script "GetBeamOriginTID" (void)
{
  SetResultValue(GetUserVariable(0,"user_beamorigintid"));
}

script "TSPWOGBeamSpawn" (int FiredByPlayer, int HowClose, int DivMapUnit)
{
  if (GetCVar("tsp_beamstyle") == 0){ int which = 0; }
  else if (GetCVar("tsp_beamstyle") == 2){ which = 2; }
  else { which = 1; }

  if (DivMapUnit == 0){ DivMapUnit = 1; }
  if (HowClose == 0){ HowClose = 1; }

  int Initialx = GetActorX(0) >> 16;
  int Initialy = GetActorY(0) >> 16;
  int Initialz = GetActorZ(0) >> 16;
  
  int InitialAngle = GetActorAngle(0);
  
  int InitialxFixed = GetActorX(0);
  int InitialyFixed = GetActorY(0);
  int InitialzFixed = GetActorZ(0);

  int Lastx = LastxFixed >> 16;
  int Lasty = LastyFixed >> 16;
  int Lastz = LastzFixed >> 16;
  
  if (FiredByPlayer == 1)
  {
    SetActivator(0,AAPTR_TARGET);

    int OriginTIDArrayNo = PlayerNumber() + 300;
	
    LastxFixed = GetActorX(PlayerTID[OriginTIDArrayNo]);
    LastyFixed = GetActorY(PlayerTID[OriginTIDArrayNo]);
    LastzFixed = GetActorZ(PlayerTID[OriginTIDArrayNo]);

    Lastx = GetActorX(PlayerTID[OriginTIDArrayNo]) >> 16;
    Lasty = GetActorY(PlayerTID[OriginTIDArrayNo]) >> 16;
    Lastz = GetActorZ(PlayerTID[OriginTIDArrayNo]) >> 16;
  }

  int Diffx = Initialx - Lastx;
  int Diffy = Initialy - Lasty;
  int Diffz = Initialz - Lastz;
  
  int LineLengthInteger = VectorLength(Diffx,Diffy);
  LineLengthInteger = VectorLength(Diffz,LineLengthInteger);

  int LineLengthFixed = LineLengthInteger << 16;
  
  if (LineLengthInteger == 0)
  {
    Terminate;
  }
  
  if (FiredByPlayer == 1)
  {
    int BezierAmountRandomizer = FixedMul(LineLengthFixed,0.8);//Random(20.0,30.0);
  }
  else
  {
    BezierAmountRandomizer = Random(1.5,4.0);
  }
  int t, Loopx, Loopy, Loopz;
  int tminus, tminussq, tminuscu, tsq, tcu;
  
  LineLengthInteger = LineLengthInteger * DivMapUnit;
  
  switch (which)
  {

    case 0:
      for (int Position = 0; Position < LineLengthInteger; Position++)
      {
        t = FixedDiv((Position << 16),(LineLengthInteger << 16));
        if (t < 0){ t =0; }
        tminus = (1.0-t);
        Loopx = ( FixedMul(tminus,LastxFixed) + FixedMul(t,InitialxFixed) );
        Loopy = ( FixedMul(tminus,LastyFixed) + FixedMul(t,InitialyFixed) );
        Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );
        if (Position % HowClose == 0)
        {
          SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0);
        }
      }
      LastxFixed = Loopx;
      LastyFixed = Loopy;
      LastzFixed = Loopz;
      Terminate;

    case 1:
      int BezierAmount = FixedDiv(LineLengthFixed,BezierAmountRandomizer);
      
      if (LastCurve < 0)
      {
        int BezierX = LastxFixed - InitialxFixed;
        BezierX = BezierX / 2;
        BezierX = BezierX + LastxFixed + random(0.0,BezierAmount);

        int BezierY = LastyFixed - InitialyFixed;
        BezierY = BezierY / 2;
        BezierY = BezierY + LastyFixed + random(0.0,BezierAmount);

        LastCurve = 1;
      }
      else if (LastCurve > 0)
      {
        BezierX = LastxFixed - InitialxFixed;
        BezierX = BezierX / 2;
        BezierX = BezierX + LastxFixed + random(-BezierAmount,0.0);

        BezierY = LastyFixed - InitialyFixed;
        BezierY = BezierY / 2;
        BezierY = BezierY + LastyFixed + random(-BezierAmount,0.0);

        LastCurve = -1;
      }
      else
      {
        LastCurve = random(-1000,1000);
        if (LastCurve <= 0)
        {
          BezierX = LastxFixed - InitialxFixed;
          BezierX = BezierX / 2;
          BezierX = BezierX + LastxFixed + random(0.0,BezierAmount);
                
          BezierY = LastyFixed - InitialyFixed;
          BezierY = BezierY / 2;
          BezierY = BezierY + LastyFixed + random(0.0,BezierAmount);
              
          LastCurve = 1;
        }
        else if (LastCurve < 0)
        {
          BezierX = LastxFixed - InitialxFixed;
          BezierX = BezierX / 2;
          BezierX = BezierX + LastxFixed + random(-BezierAmount,0.0);
              
          BezierY = LastyFixed - InitialyFixed;
          BezierY = BezierY / 2;
          BezierY = BezierY + LastyFixed + random(-BezierAmount,0.0);
              
          LastCurve = -1;
        }
      }

      if (InitialAngle >= 0.125 & InitialAngle <= 0.375 | InitialAngle >= 0.625 & InitialAngle <= 0.875 )
      {
        for (Position = 0; Position < LineLengthInteger; Position++)
        {
          t = FixedDiv((Position << 16),(LineLengthInteger << 16));
          if (t < 0){ t =0; }
          tminus = (1.0-t);
          tminussq = FixedMul(tminus,tminus);
          tsq = FixedMul(t,t);		
          Loopx = ( FixedMul(tminussq,LastxFixed) + 2 * FixedMul(FixedMul(tminus,t),BezierX) + FixedMul(tsq,InitialxFixed) );
          Loopy = ( FixedMul(tminus,LastyFixed) + FixedMul(t,InitialyFixed) );
          Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );
          if (Position % HowClose == 0)
          {
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0);
          }
        }
      }
      else
      {
        for (Position = 0; Position < LineLengthInteger; Position++)
        {
          t = FixedDiv((Position << 16),(LineLengthInteger << 16));
          if (t < 0){ t =0; }
          tminus = (1.0-t);
          tminussq = FixedMul(tminus,tminus);
          tsq = FixedMul(t,t);		
          Loopy = ( FixedMul(tminussq,LastyFixed) + 2 * FixedMul(FixedMul(tminus,t),BezierY) + FixedMul(tsq,InitialyFixed) );
          tminus = (1.0-t);
          Loopx = ( FixedMul(tminus,LastxFixed) + FixedMul(t,InitialxFixed) );
          Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );
          if (Position % HowClose == 0)
          {
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0);
          }
        }
      }
      LastxFixed = Loopx;
      LastyFixed = Loopy;
      LastzFixed = Loopz;
      Terminate;

    case 2:
      if (LastCurve < 0)
      {
        int BezierX1 = LastxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
        int BezierX2 = InitialxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
		
        int BezierY1 = LastyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
        int BezierY2 = InitialyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
        LastCurve = 1;
      }
      else if (LastCurve > 0)
      {
        BezierX1 = LastxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
        BezierX2 = InitialxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
		
        BezierY1 = LastyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
        BezierY2 = InitialyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
        LastCurve = -1;
      }
      else
      {
        LastCurve = random(-1000,1000);
        if (LastCurve <= 0)
        {
          BezierX1 = LastxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierX2 = InitialxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));

          BezierY1 = LastyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierY2 = InitialyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          LastCurve = 1;
        }
        else if (LastCurve < 0)
        {
          BezierX1 = LastxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierX2 = InitialxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));

          BezierY1 = LastyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierY2 = InitialyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          LastCurve = -1;
        }
      }
      if (InitialAngle >= 0.125 & InitialAngle <= 0.375 | InitialAngle >= 0.625 & InitialAngle <= 0.875 )
      {
        for (Position = 0; Position < LineLengthInteger; Position++)
        {
          t = FixedDiv((Position << 16),(LineLengthInteger << 16));
		  if (t < 0){ t =0; }
		  
          tminus = (1.0-t);
          tminussq = FixedMul(tminus,tminus);
          tminuscu = FixedMul(tminussq,tminus);	
          tsq = FixedMul(t,t);		
          tcu = FixedMul(tsq,t);
		  
          Loopx = ( FixedMul(tminuscu,LastxFixed) + 3 * FixedMul(tminussq,FixedMul(t,BezierX1)) + 3 * FixedMul(tminus,FixedMul(tsq,BezierX2)) + FixedMul(tcu,InitialxFixed) );

          Loopy = ( FixedMul(tminus,LastyFixed) + FixedMul(t,InitialyFixed) );
          Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );

          if (Position % HowClose == 0)
          {
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0);
          }
        }
      }
      else
      {
        for (Position = 0; Position < LineLengthInteger; Position++)
        {
          t = FixedDiv((Position << 16),(LineLengthInteger << 16));
		  if (t < 0){ t =0; }
		  
          tminus = (1.0-t);
          tminussq = FixedMul(tminus,tminus);
          tminuscu = FixedMul(tminussq,tminus);	
          tsq = FixedMul(t,t);		
          tcu = FixedMul(tsq,t);
		  
          Loopy = ( FixedMul(tminuscu,LastyFixed) + 3 * FixedMul(tminussq,FixedMul(t,BezierY1)) + 3 * FixedMul(tminus,FixedMul(tsq,BezierY2)) + FixedMul(tcu,InitialyFixed) );

          Loopx = ( FixedMul(tminus,LastxFixed) + FixedMul(t,InitialxFixed) );
          Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );

          if (Position % HowClose == 0)
          {
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0);
          }
        }
      }
      LastxFixed = Loopx;
      LastyFixed = Loopy;
      LastzFixed = Loopz;
      Terminate;
  }
}

script "TSPWOGBeam" (int which)
{
  switch (which)
  {
    case 3:
      SetActivator(0,AAPTR_TRACER);
      if(CheckFlag(0,"ISMONSTER") == FALSE)
      {
        Terminate;
      }
      else if(CheckFlag(0,"BOSS") == TRUE)
      {
        GiveInventory("BossUnTarget", 1);
        Delay(4);
        TakeInventory("BossUnTarget", 1);
        GiveInventory("BossCanTarget", 1);
        Terminate;
      }
      else if(CheckFlag(0,"NOTARGET") == TRUE)
      {
        GiveInventory("BossUnTarget", 1);
        Delay(4);
        TakeInventory("BossUnTarget", 1);
        GiveInventory("BossCanTarget", 1);
        Terminate;
      }
      else
      {
        GiveInventory("BossUnTarget", 1);
        Delay(1);
        TakeInventory("BossUnTarget", 1);
        GiveInventory("BossCanTarget", 1);
        Terminate;
      }
    case 4:
      SetActorProperty(0,APROP_RenderStyle,STYLE_Add);
      Terminate;
  }
}

script "TSPZekeMessage" (int which, int a1, int a2)
{
  int result;
  
  switch (which)
  {
    case 1:
      hudmessage (s:"[Altfire Again To Cycle Through Ammo Types]";HUDMSG_PLAIN,2,CR_GREEN,1.5,0.375,1.0);
      Terminate;
    case 2:
      hudmessage (s:"[No Alternate Shell Ammo]";HUDMSG_PLAIN,2,CR_GREEN,1.5,0.375,0.42857);
      Terminate;
    case 3:
      hudmessage (s:"[Current Ammo Depleted, Switching To Buckshot]";HUDMSG_PLAIN,2,CR_RED,1.5,0.375,1.5);
      Terminate;
    case 4:
      hudmessage (s:"[Current Ammo Depleted, Switching To Shock Shells]";HUDMSG_PLAIN,2,CR_LIGHTBLUE,1.5,0.375,1.5);
      Terminate;
    case 5:
      hudmessage (s:"[Current Ammo Depleted, Switching To HellFire Shells]";HUDMSG_PLAIN,2,CR_GOLD,1.5,0.375,1.5);
      Terminate;
    case 6:
      hudmessage (s:"[Current Ammo Depleted, Switching To Poison Shells]";HUDMSG_PLAIN,2,CR_DARKGREEN,1.5,0.375,1.5);
      Terminate;
    case 7:
      hudmessage (s:"[Buckshot Shells Selected]";HUDMSG_PLAIN,2,CR_RED,1.5,0.375,0.7142857143);
      Terminate;
    case 8:
      hudmessage (s:"[Shock Shells Selected]";HUDMSG_PLAIN,2,CR_LIGHTBLUE,1.5,0.375,0.7142857143);
      Terminate;
    case 9:
      hudmessage (s:"[HellFire Shells Selected]";HUDMSG_PLAIN,2,CR_GOLD,1.5,0.375,0.7142857143);
      Terminate;
    case 10:
      hudmessage (s:"[Poison Shells Selected]";HUDMSG_PLAIN,2,CR_DARKGREEN,1.5,0.375,0.7142857143);
      Terminate;
  }
  SetResultValue(result);
}

script "TSPSurvivorSlow" (Void)
{
   SetActorProperty(0, APROP_SPEED, 0.75);
}