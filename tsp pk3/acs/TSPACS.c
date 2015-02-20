#include "zcommon.acs"
#include "commonfuncs.h"
#include "wepFuncs.h"
#library "tspacs"

global int 50:GArray50[];
/*
  1-64 = Player TIDs
*/
  
int LastxFixedA[64];
int LastyFixedA[64];
int LastzFixedA[64];
int LastCurveA[64];

function int FixedAngMod(int fAngle)
{
  if (fAngle > 1.0){
    fAngle %= 65536; }
  else if (fAngle < 0){
    fAngle %= (-65536);
    fAngle = fAngle + 65536;}
  return fAngle;
}

script "GetShellPoolCVAR" (void)  //These all gonna get replaced soon
{
  SetResultValue(GetCVar("tsp_shellpool"));
}

script "GetToasterCVAR" (void)
{
  SetResultValue(GetCVar("tsp_toaster"));
}

script "GetFullMagCVAR" (void)
{
  SetResultValue(GetCVar("tsp_fullmags"));
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

script "TSPSetProjectilePitch" (void)  //Gonna redo in a bit
{
  SetActorPitch(0, VectorAngle (GetActorVelZ(0), sqrt(FixedMul(GetActorVelX(0),GetActorVelX(0))+FixedMul(GetActorVelY(0),GetActorVelY(0)))));
  Terminate;
}

script "TSPEnterScript1" ENTER
{

  hudmessage (s:"Blue Vertigo Presents: The Space Pirate\n \nCvars:\n \ntsp_shellpool - If set to true/1 (default), all shell types share the same ammo pool. If set to false/0, they do not and each has a separate ammo pool.
  \n\r_drawvoxels - If set to true/1 (default), voxels will be used for crossbow bolts and items. If set to true/1, models will be used for the crossbow bolts and sprites will be used for items. If you're playing this in GZDoom models will render faster, so switch if you're having performance issues, but if you're playing in ZDoom the voxels will render just fine.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_GREEN,1.5,0.375,0.1);

  TakeInventory("PlayingPickupSound", 1);
  Terminate;
}

/*script "TSPArmorScript" (void)
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
} */

script "TSPPickupSounds" (int which)
{
  if(CheckInventory("PlayingPickupSound") > 0){ terminate; }
  else{
    GiveInventory("PlayingPickupSound", 1);
    if(CheckActorClass(0,"SpacePirate") && GetPlayerInfo(PlayerNumber(),PLAYERINFO_GENDER) == 2){
      switch (which){
        case 1:
          LocalAmbientSound("melflavpickuprobo/Pistol",127);    
          Delay(41);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 2:
          LocalAmbientSound("melflavpickuprobo/ZekeShotgun",127);
          Delay(49);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 3:
          LocalAmbientSound("melflavpickuprobo/Crossbow",127);
          Delay(35);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 4:
          LocalAmbientSound("melflavpickuprobo/Ammobox50",127);
          Delay(123);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 5:
          LocalAmbientSound("melflavpickuprobo/RocketNailgunLauncher",127);
          Delay(67);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 6:
          terminate;
        case 7:
          LocalAmbientSound("melflavpickuprobo/RocketLauncher1",127);
          Delay(67);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate; }}
    else if(CheckActorClass(0,"SpacePirate")){
      switch (which){
        case 1:
          LocalAmbientSound("melflavpickup/Pistol",127);    
          Delay(46);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 2:
          LocalAmbientSound("melflavpickup/ZekeShotgun",127);
          Delay(60);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 3:
          LocalAmbientSound("melflavpickup/Crossbow",127);
          Delay(53);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 4:
          LocalAmbientSound("melflavpickup/Ammobox50",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 5:
          LocalAmbientSound("melflavpickup/RocketNailgunLauncher",127);
          Delay(69);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 6:
          terminate;
        case 7:
          LocalAmbientSound("melflavpickup/RocketLauncher1",127);
          Delay(69);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate; }}
    else if(CheckActorClass(0,"Vexler") && GetPlayerInfo(PlayerNumber(),PLAYERINFO_GENDER) == 2){
      switch (which){
        case 1:
          LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/Pistol",127);  Did it this way so it'd be easy to undo 
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 2:
          LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/ZekeShotgun",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 3:
          LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/Crossbow",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 4:
          LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/Ammobox50",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 5:
          LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/RocketNailgunLauncher",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 6:
          terminate;
        case 7:
          LocalAmbientSound("secretmessage",127); //"vexflavpickuprobo/RocketNailgunLauncher",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate; }}
    else if(CheckActorClass(0,"Vexler")){
      switch (which){
        case 1:
          LocalAmbientSound("secretmessage",127); //"vexflavpickup/Pistol",127);  Did it this way so it'd be easy to undo 
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 2:
          LocalAmbientSound("secretmessage",127); //"vexflavpickup/ZekeShotgun",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 3:
          LocalAmbientSound("secretmessage",127); //"vexflavpickup/Crossbow",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 4:
          LocalAmbientSound("secretmessage",127); //"vexflavpickup/Ammobox50",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 5:
          LocalAmbientSound("secretmessage",127); //"vexflavpickup/RocketNailgunLauncher",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate;
        case 6:
          terminate;
        case 7:
          LocalAmbientSound("secretmessage",127); //"vexflavpickup/RocketNailgunLauncher",127);
          Delay(144);
          TakeInventory("PlayingPickupSound",0x7FFFFFFF);
          terminate; }}
    else{
      TakeInventory("PlayingPickupSound",0x7FFFFFFF);
      terminate; }}
}

script "TSPHUDHealthNumberColor" ENTER
{
  if(GetActorProperty( 0, APROP_Health) >= 101){ GiveInventory("Over100Health",1); }
  else{ TakeInventory("Over100Health",1); }
  Delay(6);
  Restart;
}

script "TSPDifficultyLoadouts" ENTER
{
  if(CheckInventory("AlreadyGotOne")){ terminate; }
  else{
    GiveInventory("AlreadyGotOne",1);
    if(GameSkill() == 0) { 
      GiveInventory("TSPEasyModePickup",1); 
      if(GetCVar("tsp_usemags")){ 
        GiveInventory("TSPPistolAmmoMag",5); 
        GiveInventory("PMag15",5); }
      else{ GiveInventory("TSPPistolAmmo",75); }}
    else if(GameSkill() >= 1 && GameSkill() <= 3) { 
      GiveInventory("TSPNormalModePickup",1);
      if(GetCVar("tsp_usemags")){ 
        GiveInventory("TSPPistolAmmoMag",4); 
        GiveInventory("PMag15",4); }
      else{ GiveInventory("TSPPistolAmmo",60); }}
    else if(GameSkill() == 4){
      GiveInventory("TSPDTPPickup",1); //Looks like this doesn't exist yet
      if(GetCVar("tsp_usemags")){ 
        GiveInventory("TSPPistolAmmoMag",4); 
        GiveInventory("PMag15",4); }
      else{ GiveInventory("TSPPistolAmmo",60); }}
    else if(GameSkill() >= 5){ 
      SetActorProperty(0, APROP_SPEED, 0.75);
      GiveInventory("TSPSurvivorModePickup",1); }}
}

script "TSPIDKFAFix" ENTER
{
  if(CheckInventory("HellFireShell") == 96 && CheckInventory("PoisonShell") == 96){  //Easy way to tell if idkfa/idfa has been used
    TakeInventory("HellFireShell",0x7FFFFFFF); //Zeke stuff
    TakeInventory("PoisonShell",0x7FFFFFFF);
    TakeInventory("ElectricShell",0x7FFFFFFF);
    GiveInventory("HellFireShell",32);
    GiveInventory("PoisonShell",32);
    GiveInventory("ElectricShell",32);
    GiveInventory("BuckShotShell",96);
    GiveInventory("TSPShells",192);
    ClearPMags(1);  //Pistol stuff
    ClearAMags(1);  //AB-50 stuff
    if(!GetCVar("tsp_usemags") && GameSkill() < 5){  //If using regular ammo
      GiveInventory("TSPPistolAmmo",0x7FFFFFFF); 
      GiveInventory("AmmoBoxAmmo",0x7FFFFFFF); }
    else{ 
      TakeInventory("TSPPistolAmmo",0x7FFFFFFF);
      GiveInventory("TSPPistolAmmoMag",15);
      GiveInventory("PMag15",15); 
      TakeInventory("AmmoBoxAmmo",0x7FFFFFFF);
      GiveInventory("AmmoBoxAmmoMag",10);
      GiveInventory("AMag50",10); }
    if(CheckActorClass(0,"SpacePirate")){  //Can't put above
      if(GameSkill() >= 5){ 
        TakeInventory("Mel919mPistol",1);
        GiveInventory("Mel919mPistolLS",1);
        TakeInventory("MelAmmoBox50",1);
        GiveInventory("MelAmmoBox50LS",1); }
      else{ 
        TakeInventory("Mel919mPistolLS",1);
        GiveInventory("Mel919mPistol",1);
        TakeInventory("MelAmmoBox50LS",1);
        GiveInventory("MelAmmoBox50",1); }}}
  Delay(6);
  Restart;
}

script "ClipboxMessage" (void)
{
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){ 
    hudmessage(s:"Found an assorted ammo crate. [\cj+30 Pistol Ammo\c-][\cj+60 SMG Ammo\c-][\cv+10 Bolts\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
  else{ 
    hudmessage(s:"Found an assorted ammo crate. [\cj+2 Pistol Magazine\c-][\cj+1 SMG Magazine\c-][\cv+5 Bolts\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
}

//Shotgun Scripts

script "TSPZekeMessage" (int which)
{
  switch (which){
    case 1:
      hudmessage (s:"[Altfire Again To Cycle Through Ammo Types]";HUDMSG_PLAIN,2,CR_GREEN,1.5,0.375,1.0);
      break;
    case 2:
      hudmessage (s:"[No Alternate Shell Ammo]";HUDMSG_PLAIN,2,CR_GREEN,1.5,0.375,0.42857);
      break;
    case 3:
      hudmessage (s:"[Current Ammo Depleted, Switching To Buckshot]";HUDMSG_PLAIN,2,CR_RED,1.5,0.375,1.5);
      break;
    case 4:
      hudmessage (s:"[Current Ammo Depleted, Switching To Shock Shells]";HUDMSG_PLAIN,2,CR_LIGHTBLUE,1.5,0.375,1.5);
      break;
    case 5:
      hudmessage (s:"[Current Ammo Depleted, Switching To HellFire Shells]";HUDMSG_PLAIN,2,CR_GOLD,1.5,0.375,1.5);
      break;
    case 6:
      hudmessage (s:"[Current Ammo Depleted, Switching To Poison Shells]";HUDMSG_PLAIN,2,CR_DARKGREEN,1.5,0.375,1.5);
      break;
    case 7:
      hudmessage (s:"[Buckshot Shells Selected]";HUDMSG_PLAIN,2,CR_RED,1.5,0.375,0.7142857143);
      break;
    case 8:
      hudmessage (s:"[Shock Shells Selected]";HUDMSG_PLAIN,2,CR_LIGHTBLUE,1.5,0.375,0.7142857143);
      break;
    case 9:
      hudmessage (s:"[HellFire Shells Selected]";HUDMSG_PLAIN,2,CR_GOLD,1.5,0.375,0.7142857143);
      break;
    case 10:
      hudmessage (s:"[Poison Shells Selected]";HUDMSG_PLAIN,2,CR_DARKGREEN,1.5,0.375,0.7142857143);
      break; }
}

script "ShellPoolChange" ENTER
{
  int maxshells, elecover, hellover, psnover, overshells, loopcounter;
  int lastshellpool = GetCVar("tsp_shellpool");
  Delay(3);
  while(true){
    if((GetCVar("tsp_shellpool") != lastshellpool) && !(GetCVar("tsp_shellpool"))){
      lastshellpool = GetCVar("tsp_shellpool");
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxshells = 32; }
       else{ maxshells = 16; }
      if(CheckInventory("ElectricShell") > maxshells){ 
        elecover = CheckInventory("ElectricShell") - maxshells;
        TakeInventory("ElectricShell",elecover); }
      if(CheckInventory("HellFireShell") > maxshells){ 
        hellover = CheckInventory("HellFireShell") - maxshells;
        TakeInventory("HellFireShell",hellover); }
      if(CheckInventory("PoisonShell") > maxshells){ 
        psnover = CheckInventory("PoisonShell") - maxshells;
        TakeInventory("PoisonShell",psnover); }
      overshells = elecover + hellover + psnover;
      loopcounter = 0;
      while(overshells > 0){
        if(CheckInventory("ElectricShell") < maxshells && overshells > 0){ 
          --overshells;
          GiveInventory("TSPShells",1);
          GiveInventory("ElectricShell",1); }
        if(CheckInventory("HellFireShell") < maxshells && overshells > 0){ 
          --overshells;
          GiveInventory("TSPShells",1);
          GiveInventory("HellFireShell",1); }
        if(CheckInventory("PoisonShell") < maxshells && overshells > 0){ 
          --overshells;
          GiveInventory("TSPShells",1);
          GiveInventory("PoisonShell",1); }
        if(loopcounter > maxshells){ overshells = 0; }
        ++loopcounter; }}
    else if(GetCVar("tsp_shellpool") != lastshellpool){
      lastshellpool = GetCVar("tsp_shellpool"); }
    Delay(6); }
}

script "ShellPickup" (int which, int howmany, int msg)
{
  int shells, maxshells, specshells, maxspecshells, result, giveamt;
  if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxshells = 96; }
   else{ maxshells = 48; }
  if(which==4){ maxspecshells = maxshells; }
   else{ maxspecshells = maxshells / 3; }
  if(GetCVar("tsp_shellpool") && which != 4){
    shells = CheckInventory("ElectricShell") + CheckInventory("HellFireShell") + CheckInventory("PoisonShell");
    if(shells < maxshells){ 
      giveamt = maxshells - shells;
      result = 1; }}
  else{
    switch (which){
      case 1:
        specshells = CheckInventory("ElectricShell");
        break;
      case 2:
        specshells = CheckInventory("HellFireShell");
        break;
      case 3:
        specshells = CheckInventory("PoisonShell");
        break;
      case 4:
        specshells = CheckInventory("BuckShotShell");
        break; }
    if(specshells < maxspecshells){ 
      giveamt = maxspecshells - specshells;
      result = 1; }}
  if(result){
    if(howmany < giveamt){ giveamt = howmany; } 
    GiveInventory("TSPShells",giveamt);
    switch (which){
      case 1:
        GiveInventory("ElectricShell",giveamt);
        if(msg){ ShellMessage(1,giveamt); }
        break;
      case 2:
        GiveInventory("HellFireShell",giveamt);
        if(msg){ ShellMessage(2,giveamt); }
        break;
      case 3:
        GiveInventory("PoisonShell",giveamt);
        if(msg){ ShellMessage(3,giveamt); }
        break;
      case 3:
        GiveInventory("BuckShotShell",giveamt);
        if(msg){ ShellMessage(4,giveamt); }
        break; }}
  setresultvalue(result);
}

//Pistol Scripts

script "PMagChange" ENTER
{
  int ammo, maxammo, mags, maxmags;
  int lastusemags = GetCVar("tsp_usemags");
  Delay(3);
  while(true){
    if((GetCVar("tsp_usemags") != lastusemags) && !(GetCVar("tsp_usemags"))){
      lastusemags = GetCVar("tsp_usemags");
      ammo = CountPMags();
      ClearPMags(1);
      GiveInventory("TSPPistolAmmo",ammo); }
    else if((GetCVar("tsp_usemags") != lastusemags) && (GetCVar("tsp_usemags"))){
      lastusemags = GetCVar("tsp_usemags");
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 15; }
      else{ maxmags = 10; }
      ammo = CheckInventory("TSPPistolAmmo");
      TakeInventory("TSPPistolAmmo",0x7FFFFFFF);
      if((ammo / maxmags) >= 15){
        GiveInventory("TSPPistolAmmoMag",maxmags);
        GiveInventory("PMag15",maxmags); }
      else{
        mags = CheckInventory("AmmoBoxAmmoMag");
        while(ammo > 15 && mags < maxmags){
          ammo = ammo - 15;
          mags++;
          GiveInventory("TSPPistolAmmoMag",1);
          GiveInventory("PMag15",1); }
        if(ammo > 0){ GivePMag(ammo,0,1); }}}
    Delay(6); }
}

script "PMagSpawn" (int chance, int LSchance)
{
  int SpawnX, SpawnY, SpawnZ, SpawnAngle;
  int roll;
  roll = random(1,255);
  if((GameSkill() < 5 && roll <= chance) || (GameSkill() >= 5 && roll <= LSchance)){
    SpawnX = GetActorX(0);
    SpawnY = GetActorY(0);
    SpawnZ = GetActorZ(0);
    SpawnAngle = GetActorAngle(0);
    SpawnForced("PistolAmmoDropper",SpawnX,SpawnY,SpawnZ,0,SpawnAngle); }
}

script "PistolMagPickup" (int howmanyclip, int howmanyammo, int msg)
{
  int ammo, maxammo, mags, maxmags, smallestmag;
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 300; }
    else{ maxammo = 150; }
    ammo = CheckInventory("TSPPistolAmmo");
    if(ammo < maxammo){
      if(howmanyammo){ GiveInventory("TSPPistolAmmo",howmanyammo); }
      else if(howmanyclip == 16){ GiveInventory("TSPPistolAmmo",10); }
      else{ GiveInventory("TSPPistolAmmo",5); }
      setresultvalue(1); }
    else{ setresultvalue(0); }}
  else{
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 15; }
    else{ maxmags = 10; }
    mags = CheckInventory("TSPPistolAmmoMag");
    if(howmanyclip == 16){ howmanyclip = 15; }
    if(mags < maxmags){
      GivePMag(howmanyclip,msg,1);
      setresultvalue(1); }
    else{ 
      smallestmag = GetSmallestPMag();
      if(howmanyclip > smallestmag){ 
        GivePMag(howmanyclip,msg,0);
        TakePMag(smallestmag,1,0);
        setresultvalue(1); }
      else{ setresultvalue(0); }}}
}

script "PistolReloadCheck" (int which)
{
  int result;
  if(!which){
    if(!GetCVar("tsp_usemags") && GameSkill() < 5){
      if(CheckInventory("TSPPistolAmmo")){ result = 1; }}
    else if(CheckInventory("TSPPistolAmmoMag")){ result = 1; }}
  else{
    if((!GetCVar("tsp_usemags") && GameSkill() < 5)){
      if (!CheckInventory("TSPPistolAmmo") || CheckInventory("AutoPistolMag") == 15){ result = 1; }}
    else if((CheckInventory("AutoPistolMag") >= GetLargestPMag()) || !CheckInventory("TSPPistolAmmoMag")){
      result = 1; }}
  setresultvalue(result);
}

script "PMagOut" (void)
{
  int ammo, maxammo, mags, maxmags, smallestmag;
  int loadedammo, ammobuffer;
  loadedammo = CheckInventory("AutoPistolMag");
  TakeInventory("AutoPistolMag",0x7FFFFFFF);     
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 300; }
    else{ maxammo = 150; }
    ammo = CheckInventory("TSPPistolAmmo");
    if(loadedammo > (maxammo - ammo)){ ammobuffer = loadedammo - (maxammo - ammo); }
    loadedammo = loadedammo - ammobuffer;
    GiveInventory("TSPPistolAmmo",loadedammo);
    SetUserVariable(0,"user_PMagInGun",ammobuffer);
    TakePMag(0,1,0); }
  else{
    if(!loadedammo){ TakePMag(0,1,0); }
    else{
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 15; }
      else{ maxmags = 10; }
      mags = CheckInventory("TSPPistolAmmoMag");
      if(mags < maxmags){ GivePMag(loadedammo,0,1); }
      else{
        smallestmag = GetSmallestPMag();
        /*if(loadedammo > smallestmag){     
          TakeAMag(smallestmag,1,0);
          GiveAMag(loadedammo,0,0); }
        else{ SetUserVariable(0,"user_PMagInGun",loadedammo); }}}}*/
        SetUserVariable(0,"user_PMagInGun",loadedammo); }}}
}

script "PMagIn" (void)
{
  int mags, maxmags, smallestmag, largestmag;
  int ammobuffer;
  ammobuffer = GetUserVariable(0,"user_PMagInGun");     
  SetUserVariable(0,"user_PMagInGun",0);
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    GiveInventory("AutoPistolMag",ammobuffer);
    while(CheckInventory("AutoPistolMag") < 15 && CheckInventory("TSPPistolAmmo")){
      TakeInventory("TSPPistolAmmo",1);
      GiveInventory("AutoPistolMag",1); }}
  else{
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 15; }
    else{ maxmags = 10; }
    largestmag = GetLargestPMag();
    TakePMag(largestmag,0,1);
    GiveInventory("AutoPistolMag",largestmag);
    if(ammobuffer){ GivePMag(ammobuffer,0,1); }}
}

script "TSPHUDPistolAmmoDisplay" ENTER
{
  TakeInventory("TSPPistolAmmoDummy",0x7FFFFFFF);
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    int ammo = CheckInventory("TSPPistolAmmo");
    GiveInventory("TSPPistolAmmoDummy",ammo); }
  else{
    ammo = CheckInventory("TSPPistolAmmoMag");
    GiveInventory("TSPPistolAmmoDummy",ammo); }
  Delay(1);
  Restart;
}

//MP40 Scripts

script "MP40ReloadCheck" (int which)
{
  int result;
  if(!which){
    if(!GetCVar("tsp_usemags") && GameSkill() < 5){
      if(CheckInventory("TSPPistolAmmo")){ result = 1; }}
    else if(CheckInventory("TSPPistolAmmoMag")){ result = 1; }}
  else{
    if((!GetCVar("tsp_usemags") && GameSkill() < 5)){
      if (!CheckInventory("TSPPistolAmmo") || CheckInventory("MP40Mag") == 30){ result = 1; }}
    else if((CheckInventory("MP40Mag") >= GetLargestPMag()) || !CheckInventory("TSPPistolAmmoMag")){
      result = 1; }}
  setresultvalue(result);
}

script "MP40MagOut" (void)
{
  int ammo, maxammo, mags, maxmags, smallestmag;
  int loadedammo, loadedammo2, ammobuffer;
  loadedammo = CheckInventory("MP40Mag");
  TakeInventory("MP40Mag",0x7FFFFFFF);     
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 300; }
    else{ maxammo = 150; }
    ammo = CheckInventory("TSPPistolAmmo");
    if(loadedammo > (maxammo - ammo)){ ammobuffer = loadedammo - (maxammo - ammo); }
    loadedammo = loadedammo - ammobuffer;
    GiveInventory("TSPPistolAmmo",loadedammo);
    SetUserVariable(0,"user_MP40MagInGun",ammobuffer);
    TakePMag(0,1,0); }
  else{
    if(!loadedammo){ TakePMag(0,1,0); }
    else{
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 15; }
      else{ maxmags = 10; }
      mags = CheckInventory("TSPPistolAmmoMag");
      if(loadedammo > 15){
        loadedammo2 = loadedammo / 2;
        loadedammo = loadedammo - loadedammo2;
        if((mags + 1) < maxmags){ 
          GivePMag(loadedammo,0,1); 
          GivePMag(loadedammo2,0,1); }
        else{
          smallestmag = GetSmallestPMag();
          if(loadedammo > smallestmag){     
            TakePMag(smallestmag,1,0);
            GivePMag(loadedammo,0,0);
            smallestmag = GetSmallestPMag();
            if(loadedammo2 > smallestmag){     
              TakePMag(smallestmag,1,0);
              GivePMag(loadedammo2,0,0); }
            /*if(loadedammo > smallestmag){     
              TakeAMag(smallestmag,1,0);
              GiveAMag(loadedammo,0,0); }
            else{ SetUserVariable(0,"user_MP40MagInGun",loadedammo); }}*/
            SetUserVariable(0,"user_MP40MagInGun",loadedammo); }
          else{     
            SetUserVariable(0,"user_MP40MagInGun",loadedammo);
            TakePMag(loadedammo2,1,0); }}}
      else{
        if(mags < maxmags){ GivePMag(loadedammo,0,1); }
        else{
          smallestmag = GetSmallestPMag();
          /*if(loadedammo > smallestmag){     
            TakeAMag(smallestmag,1,0);
            GiveAMag(loadedammo,0,0); }
          else{ SetUserVariable(0,"user_MP40MagInGun",loadedammo); }}}}}*/
          SetUserVariable(0,"user_MP40MagInGun",loadedammo); }}}}
}

script "MP40MagIn" (void)
{
  int mags, maxmags, smallestmag, largestmag, largestmag2;
  int ammobuffer;
  ammobuffer = GetUserVariable(0,"user_MP40MagInGun");     
  SetUserVariable(0,"user_MP40MagInGun",0);
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    GiveInventory("MP40Mag",ammobuffer);
    while(CheckInventory("MP40Mag") < 30 && CheckInventory("TSPPistolAmmo")){
      TakeInventory("TSPPistolAmmo",1);
      GiveInventory("AutoPistolMag",1); }}
  else{
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 15; }
    else{ maxmags = 10; }
    largestmag = GetLargestPMag();
    TakePMag(largestmag,0,1);
    largestmag2 = GetLargestPMag();
    TakePMag(largestmag2,0,1);
    largestmag = largestmag + largestmag2;
    GiveInventory("AutoPistolMag",largestmag);
    if(ammobuffer){ GivePMag(ammobuffer,0,1); }}
}

script "TSPHUDMP40AmmoDisplay" ENTER
{
  TakeInventory("MP40DummyAmmo",0x7FFFFFFF);
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    int ammo = CheckInventory("TSPPistolAmmo");
    GiveInventory("MP40DummyAmmo",ammo); }
  else{
    ammo = CheckInventory("TSPPistolAmmoMag");
    int ammomod = ammo % 2;
    ammo = (ammo / 2) + ammomod;
    GiveInventory("MP40DummyAmmo",ammo); }
  Delay(1);
  Restart;
}

//AB-50 Scripts

script "AMagChange" ENTER
{
  int ammo, maxammo, mags, maxmags;
  int lastusemags = GetCVar("tsp_usemags");
  Delay(3);
  while(true){
    if((GetCVar("tsp_usemags") != lastusemags) && !(GetCVar("tsp_usemags"))){
      lastusemags = GetCVar("tsp_usemags");
      ammo = CountAMags();
      ClearAMags(1);
      GiveInventory("AmmoBoxAmmo",ammo); }
    else if((GetCVar("tsp_usemags") != lastusemags) && (GetCVar("tsp_usemags"))){
      lastusemags = GetCVar("tsp_usemags");
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 10; }
      else{ maxmags = 5; }
      ammo = CheckInventory("AmmoBoxAmmo");
      TakeInventory("AmmoBoxAmmo",0x7FFFFFFF);
      if((ammo / maxmags) >= 50){
        GiveInventory("AmmoBoxAmmoMag",maxmags);
        GiveInventory("AMag50",maxmags); }
      else{
        mags = CheckInventory("AmmoBoxAmmoMag");
        while(ammo > 50 && mags < maxmags){
          ammo = ammo - 50;
          mags++;
          GiveInventory("AmmoBoxAmmoMag",1);
          GiveInventory("AMag50",1); }
        if(ammo > 0){ GiveAMag(ammo,0,1); }}}
    Delay(6); }
}

script "AMagSpawn" (int chance, int LSchance)
{
  int SpawnX, SpawnY, SpawnZ, SpawnAngle;
  int roll;
  roll = random(1,255);
  if((GameSkill() < 5 && roll <= chance) || (GameSkill() >= 5 && roll <= LSchance)){
    SpawnX = GetActorX(0);
    SpawnY = GetActorY(0);
    SpawnZ = GetActorZ(0);
    SpawnAngle = GetActorAngle(0);
    SpawnForced("AB50AmmoDropper",SpawnX,SpawnY,SpawnZ,0,SpawnAngle); }
}

script "AB50MagPickup" (int howmanyclip, int howmanyammo, int msg)
{
  int ammo, maxammo, mags, maxmags, smallestmag;
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 300; }
    else{ maxammo = 150; }
    ammo = CheckInventory("AmmoBoxAmmo");
    if(ammo < maxammo){
      if(howmanyammo){ GiveInventory("AmmoBoxAmmo",howmanyammo); }
      else if(howmanyclip == 51){ GiveInventory("AmmoBoxAmmo",15); }
      else{ GiveInventory("AmmoBoxAmmo",10); }
      setresultvalue(1); }
    else{ setresultvalue(0); }}
  else{
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 10; }
    else{ maxmags = 5; }
    mags = CheckInventory("AmmoBoxAmmoMag");
    if(howmanyclip == 51){ howmanyclip = 50; }
    if(mags < maxmags){
      GiveAMag(howmanyclip,msg,1);
      setresultvalue(1); }
    else{ 
      smallestmag = GetSmallestAMag();
      if(howmanyclip > smallestmag){ 
        GiveAMag(howmanyclip,msg,0);
        TakeAMag(smallestmag,1,0);
        setresultvalue(1); }
      else{ setresultvalue(0); }}}
}

script "AB50ReloadCheck" (int which)
{
  int result;
  if(!which){
    if(!GetCVar("tsp_usemags") && GameSkill() < 5){
      if(CheckInventory("AmmoBoxAmmo")){ result = 1; }}
    else if(CheckInventory("AmmoBoxAmmoMag")){ result = 1; }}
  else{
    if((!GetCVar("tsp_usemags") && GameSkill() < 5)){
      if (!CheckInventory("AmmoBoxAmmo") || CheckInventory("AmmoBoxMag") == 50){ result = 1; }}
    else if((CheckInventory("AmmoBoxMag") >= GetLargestAMag()) || !CheckInventory("TSPPistolAmmoMag")){
      result = 1; }}
  setresultvalue(result);
}

script "AMagOut" (void)
{
  int ammo, maxammo, mags, maxmags, smallestmag;
  int loadedammo, ammobuffer;
  loadedammo = CheckInventory("AmmoBoxMag");
  TakeInventory("AmmoBoxMag",0x7FFFFFFF);     
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 300; }
    else{ maxammo = 150; }
    ammo = CheckInventory("AmmoBoxAmmo");
    if(loadedammo > (maxammo - ammo)){ ammobuffer = loadedammo - (maxammo - ammo); }
    loadedammo = loadedammo - ammobuffer;
    GiveInventory("AmmoBoxAmmo",loadedammo);
    SetUserVariable(0,"user_AMagInGun",ammobuffer);
    TakeAMag(0,1,0); }
  else{
    if(!loadedammo){
      TakeAMag(0,1,0); }
    else{
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 10; }
      else{ maxmags = 5; }
      mags = CheckInventory("AmmoBoxAmmoMag");
      if(mags < maxmags){ GiveAMag(loadedammo,0,1); }
      else{
        smallestmag = GetSmallestAMag();
        /*if(loadedammo > smallestmag){     
          TakeAMag(smallestmag,1,0);
          GiveAMag(loadedammo,0,0); }
        else{ SetUserVariable(0,"user_AMagInGun",loadedammo); }}}}*/
        SetUserVariable(0,"user_AMagInGun",loadedammo); }}}
}

script "AMagIn" (void)
{
  int mags, maxmags, smallestmag, largestmag;
  int ammobuffer;
  ammobuffer = GetUserVariable(0,"user_AMagInGun");     
  SetUserVariable(0,"user_AMagInGun",0);
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    GiveInventory("AmmoBoxMag",ammobuffer);
    while(CheckInventory("AmmoBoxMag") < 50 && CheckInventory("AmmoBoxAmmo")){
      TakeInventory("AmmoBoxAmmo",1);
      GiveInventory("AmmoBoxMag",1); }}
  else{
    if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxmags = 10; }
    else{ maxmags = 5; }
    largestmag = GetLargestAMag();
    TakeAMag(largestmag,0,1);
    GiveInventory("AmmoBoxMag",largestmag);
    if(ammobuffer){ GiveAMag(ammobuffer,0,1); }}
}

script "TSPHUDAB50AmmoDisplay" ENTER
{
  TakeInventory("AmmoBoxAmmoDummy",0x7FFFFFFF);
  if(!GetCVar("tsp_usemags") && GameSkill() < 5){
    int ammo = CheckInventory("AmmoBoxAmmo");
    GiveInventory("AmmoBoxAmmoDummy",ammo); }
  else{
    ammo = CheckInventory("AmmoBoxAmmoMag");
    GiveInventory("AmmoBoxAmmoDummy",ammo); }
  Delay(1);
  Restart;
}

//Dahlia Scripts

script "BoltPickup" (int which, int howmany, int msg)
{
  int ammo, maxammo, giveamt, result;
  switch (which){
    case 1:
      ammo = CheckInventory("DahliaNormalAmmo");
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 60; }
      else{ maxammo = 40; }
      break;
    case 2:
      ammo = CheckInventory("DahliaExplosiveAmmo");
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 40; }
      else{ maxammo = 20; }
      break;
    /*case 3:
      ammo = CheckInventory("DahliaNormalAmmo");
      if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 60; }
      else{ maxammo = 40; }
      break;*/ }
  giveamt = maxammo - ammo;
  if(howmany < giveamt){ giveamt = howmany; } 
  if(giveamt > 0){ 
    result = 1;
    switch (which){
      case 1:
        GiveInventory("DahliaNormalAmmo",giveamt);
        if(msg){ BoltMessage(1,giveamt); }
        break;
      case 2:
        GiveInventory("DahliaExplosiveAmmo",giveamt);
        if(msg){ BoltMessage(2,giveamt); }
        break;
      /*case 3:
        GiveInventory("AmmoBoxAmmo",giveamt);
        if(msg){ BoltMessage(3,giveamt); }
        break;*/ }}
  setresultvalue(result);
}

script "TSPBoltStickScript" (void)
{
  int NewTID = UniqueTID();
  Thing_ChangeTID (0,NewTID);
  int BoltAngle = GetActorAngle(0); 
  int BoltX = GetActorZ(0);
  SetActivator(0,AAPTR_TRACER);
  int TracerAngle = GetActorAngle(0);
  int TracerX = GetActorZ(0);
  SetUserVariable(NewTID,"user_height",BoltX - TracerX);
  SetUserVariable(NewTID,"user_angle",FixedAngMod(BoltAngle - TracerAngle));
}

script "TSPBoltExplodeScript" (int which)
{
  int newtid;
  int BoltX, BoltY, BoltZ, BoltZVar, TracerX, TracerY, TracerZ;
  int BoltAngle, TracerAngle;
  //int BoltPitch, TracerPitch;
  newtid = UniqueTID();
  BoltX = GetActorX(0);
  BoltY = GetActorY(0);
  BoltZ = GetActorZ(0);
  BoltZVar = GetUserVariable(0,"user_height");
  BoltAngle = GetActorAngle(0);
  //BoltPitch = GetActorPitch(0);
  if(which == 1){
    SpawnForced("BoltExplodeDeath",BoltX,BoltY,BoltZ,newtid,BoltAngle);
    /* SetActorPitch(newtid,BoltPitch); */}
  else if(which == 2){
    SetActivator(0,AAPTR_TRACER);
    TracerX = GetActorX(0);
    TracerY = GetActorY(0);
    TracerZ = GetActorZ(0);
    TracerAngle = GetActorAngle(0);
    //TracerPitch = GetActorPitch(0);
    SpawnForced("BoltExplodeXDeath",TracerX,TracerY,TracerZ,newtid,TracerAngle);
    /* SetActorPitch(newtid,TracerPitch); */}
  else{
    SetActivator(0,AAPTR_TRACER);
    if(CheckFlag(0,"NORADIUSDMG")){
      Thing_Damage2(0,Random(30,90),"BoltScriptDmg"); }
    else{
      Thing_Damage2(0,Random(128,384),"BoltScriptDmg"); }
    TracerX = GetActorX(0);
    TracerY = GetActorY(0);
    TracerZ = GetActorZ(0);
    TracerAngle = GetActorAngle(0);
    //TracerPitch = GetActorPitch(0);
    SpawnForced("BoltExplodeXDeath",TracerX,TracerY,TracerZ + BoltZVar,newtid,TracerAngle);
    /* SetActorPitch(newtid,TracerPitch); */}
}

//ToolBox Scripts

script "RocketPickup" (int howmany, int msg)
{
  int ammo, maxammo, giveamt, result;
  ammo = CheckInventory("ToolboxAmmo");
  if(CheckInventory("Backpack2") || CheckInventory("Backpack")){ maxammo = 60; }
  else{ maxammo = 30; }
  giveamt = maxammo - ammo;
  if(howmany < giveamt){ giveamt = howmany; } 
  if(giveamt > 0){ 
    result = 1;
    GiveInventory("ToolboxAmmo",giveamt);
    if(msg){ RocketMessage(giveamt); }}
  setresultvalue(result);
}

script "TSPBeamDeath" (void)
{
  SetActorProperty(0,APROP_RenderStyle,STYLE_Add);
}

Script "PlayerTID" ENTER
{
  int PlayerNumberCheck = PlayerNumber();
  if(GArray50[PlayerNumberCheck] == 0  ||  ActivatorTID () == 0){
    int NewPlayerTID = UniqueTID();
    GArray50[PlayerNumberCheck] = NewPlayerTID;
    Thing_ChangeTid(0,NewPlayerTID); }
}

Script "DProjTID" (void)
{
  int NewTID = UniqueTID();
  SetUserVariable(0,"user_DProjTID",NewTID);
  SetResultValue(NewTID);
}

Script "BeamTID" (void)
{
  int pnum = ActivatorTID();
  SetResultValue(pnum);
}

function int GetToaster(int WhichCVar) //More will be done with this later
{
  int toaster = GetCVar("tsp_toaster");
  return toaster;
}

script "TSPWOGBeamSpawn" (int FiredByPlayer)
{
  int newtid, Position;
  int LastX, LastY, LastZ, LastXFixed, LastYFixed, LastZFixed;
  int beamstyle, toaster;
  int lastcurve;
  int HowClose, DivMapUnit;
  int BezierX, BezierY, BezierAmount;
  int BezierX1, BezierX2, BezierY1, BezierY2;
  int t, Loopx, Loopy, Loopz;
  int tminus, tminussq, tminuscu, tsq, tcu;
  
  int InitialxFixed = GetActorX(0);
  int InitialyFixed = GetActorY(0);
  int InitialzFixed = GetActorZ(0);

  int Initialx = InitialxFixed >> 16;
  int Initialy = InitialyFixed >> 16;
  int Initialz = InitialzFixed >> 16;

  toaster = GetToaster(1);

  if (toaster <= 0){
    HowClose = 1; 
    DivMapUnit = 1; }
  else if (toaster == 1){
    HowClose = 4; 
    DivMapUnit = 1; }
  else{
    HowClose = 6; 
    DivMapUnit = 1; }

  newtid = UniqueTID();
  Thing_ChangeTid(0,newtid);

  SetActivator(0,AAPTR_TARGET);

    /*
  if (ClassifyActor(0) &  ACTOR_PLAYER){ int FiredByPlayer = 1; }


  if (GetCVar("tsp_beamstyle") == 0){ beamstyle = 0; }
  else if (GetCVar("tsp_beamstyle") == 2 && FiredByPlayer){ beamstyle = 1; }
  else if (GetCVar("tsp_beamstyle") == 2){ beamstyle = 2; }
  else { beamstyle = 1; }  */

  if (GetCVar("tsp_beamstyle") == 0){ beamstyle = 0; }
  else if (GetCVar("tsp_beamstyle") == 2){ beamstyle = 2; }
  else { beamstyle = 1; }

  if (FiredByPlayer == 1){
    int DummyProjTID = GetUserVariable(0,"user_DProjTID");
    LastxFixed = GetActorX(DummyProjTID);
    LastyFixed = GetActorY(DummyProjTID);
    LastzFixed = GetActorZ(DummyProjTID); 
    lastcurve = 0; 
    int pnum = PlayerNumber() + 1; }
  else{
    pnum = ActivatorTID();     
    LastxFixed = LastxFixedA[pnum];
    LastyFixed = LastyFixedA[pnum];
    LastzFixed = LastzFixedA[pnum];
    lastcurve = LastCurveA[pnum]; }

  Thing_ChangeTid(newtid,pnum);
  
  Lastx = LastxFixed >> 16;
  Lasty = LastyFixed >> 16;
  Lastz = LastzFixed >> 16;
  
  int InitialAngle = VectorAngle(LastxFixed - InitialxFixed, LastyFixed - InitialyFixed);

  int Diffx = Initialx - Lastx;
  int Diffy = Initialy - Lasty;
  int Diffz = Initialz - Lastz;
  
  int LineLengthInteger = VectorLength(Diffx,Diffy);
  LineLengthInteger = VectorLength(Diffz,LineLengthInteger);

  int LineLengthFixed = LineLengthInteger << 16;

  int xLengthFixed = abs(LastxFixed - InitialxFixed);
  int yLengthFixed = abs(LastyFixed - InitialyFixed);
  int zLengthFixed = abs(LastzFixed - InitialzFixed);

  if (LineLengthInteger == 0){ Terminate; }
  
  if (FiredByPlayer == 1){ BezierAmount = 0.5; }
  else{ BezierAmount = 3.0; }
  
  LineLengthInteger = LineLengthInteger * DivMapUnit;
  
  switch (beamstyle)
  {
    case 0:
      for (Position = 0; Position < LineLengthInteger; Position++){
        t = FixedDiv((Position << 16),(LineLengthInteger << 16));
        if (t < 0){ t =0; }
        tminus = (1.0-t);
        Loopx = ( FixedMul(tminus,LastxFixed) + FixedMul(t,InitialxFixed) );
        Loopy = ( FixedMul(tminus,LastyFixed) + FixedMul(t,InitialyFixed) );
        Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );
        if (Position % HowClose == 0){
          SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0); }}
      break;

    case 1:
      while(BezierX == 0 || BezierY == 0){ //still not sure what is causing the zeroing bug, but this workaround works
        if (LastCurve < 0){
          BezierX = random(InitialxFixed,LastxFixed) + FixedMul(xLengthFixed,random(1,BezierAmount));
          BezierY = random(InitialyFixed,LastyFixed) + FixedMul(yLengthFixed,random(1,BezierAmount));
          LastCurve = 1; }
        else if (LastCurve > 0){
          BezierX = random(InitialxFixed,LastxFixed) - FixedMul(xLengthFixed,random(1,BezierAmount));
          BezierY = random(InitialyFixed,LastyFixed) - FixedMul(yLengthFixed,random(1,BezierAmount));
          LastCurve = -1; }
        else{
          LastCurve = random(-1000,1000);
          if (LastCurve <= 0){
            BezierX = random(InitialxFixed,LastxFixed) + FixedMul(xLengthFixed,random(1,BezierAmount));
            BezierY = random(InitialyFixed,LastyFixed) + FixedMul(yLengthFixed,random(1,BezierAmount));
            LastCurve = 1; }
          else if (LastCurve < 0){
            BezierX = random(InitialxFixed,LastxFixed) - FixedMul(xLengthFixed,random(1,BezierAmount));
            BezierY = random(InitialyFixed,LastyFixed) - FixedMul(yLengthFixed,random(1,BezierAmount));
            LastCurve = -1; }}}
      if ((InitialAngle >= 0.125 && InitialAngle <= 0.375) || (InitialAngle >= 0.625 && InitialAngle <= 0.875)){
        for (Position = 0; Position < LineLengthInteger; Position++){
          t = FixedDiv((Position << 16),(LineLengthInteger << 16));
          if (t < 0){ t =0; }
          tminus = (1.0-t);
          tminussq = FixedMul(tminus,tminus);
          tsq = FixedMul(t,t);        
          Loopx = ( FixedMul(tminussq,LastxFixed) + 2 * FixedMul(FixedMul(tminus,t),BezierX) + FixedMul(tsq,InitialxFixed) );
          Loopy = ( FixedMul(tminus,LastyFixed) + FixedMul(t,InitialyFixed) );
          Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );
          if (Position % HowClose == 0){
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0); }}}
      else{
        for (Position = 0; Position < LineLengthInteger; Position++){
          t = FixedDiv((Position << 16),(LineLengthInteger << 16));
          if (t < 0){ t =0; }
          tminus = (1.0-t);
          tminussq = FixedMul(tminus,tminus);
          tsq = FixedMul(t,t);        
          Loopy = ( FixedMul(tminussq,LastyFixed) + 2 * FixedMul(FixedMul(tminus,t),BezierY) + FixedMul(tsq,InitialyFixed) );
          Loopx = ( FixedMul(tminus,LastxFixed) + FixedMul(t,InitialxFixed) );
          Loopz = ( FixedMul(tminus,LastzFixed) + FixedMul(t,InitialzFixed) );
          if (Position % HowClose == 0){
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0); }}}
      break;

    case 2:
      while(BezierX1 == 0 || BezierX2 == 0 || BezierY1 == 0 || BezierY2 == 0){ //still not sure what is causing the zeroing bug, but this workaround works
        if (LastCurve < 0){
          BezierX1 = LastxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierX2 = InitialxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierY1 = LastyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierY2 = InitialyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          LastCurve = 1; }
        else if (LastCurve > 0){
          BezierX1 = LastxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierX2 = InitialxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierY1 = LastyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
          BezierY2 = InitialyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
          LastCurve = -1;}
        else{
          LastCurve = random(-1000,1000);
          if (LastCurve <= 0){
            BezierX1 = LastxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
            BezierX2 = InitialxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
            BezierY1 = LastyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
            BezierY2 = InitialyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
            LastCurve = 1; }
          else if (LastCurve < 0){
            BezierX1 = LastxFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
            BezierX2 = InitialxFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
            BezierY1 = LastyFixed - random((LineLengthFixed / 8),(LineLengthFixed / 16));
            BezierY2 = InitialyFixed + random((LineLengthFixed / 8),(LineLengthFixed / 16));
            LastCurve = -1; }}}
 
      if ( (InitialAngle >= 0.125 && InitialAngle <= 0.375) || (InitialAngle >= 0.625 && InitialAngle <= 0.875) ){
        for (Position = 0; Position < LineLengthInteger; Position++){
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
          if (Position % HowClose == 0){
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0); }}}
      else{
        for (Position = 0; Position < LineLengthInteger; Position++){
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
          if (Position % HowClose == 0){
            SpawnForced("WOGMissileTrail",Loopx,Loopy,Loopz,0,0); }}}
      break;
  }
  
  LastxFixedA[pnum] = Loopx;
  LastyFixedA[pnum] = Loopy; 
  LastzFixedA[pnum] = Loopz; 
  LastCurveA[pnum] = lastcurve;
  setresultvalue(1);
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

/*//////////////////////////////////////////

#define AMMOGIVE_Pistol          2
#define AMMOGIVE_BuckShell       3
#define AMMOGIVE_ShockShell      31
#define AMMOGIVE_HellShell       32
#define AMMOGIVE_PoisonShell     33
#define AMMOGIVE_AmmoBoxAmmo     4
#define AMMOGIVE_Bolt            41
#define AMMOGIVE_XBolt           42
#define AMMOGIVE_Rocket          5

script "AmmoGiveLS" (int which, int GiveNormal, int GiveLS, int msgthrow) 

which - which ammo according to above definitions, can use number or AMMOGIVE_name

GiveNormal - amount given on non-LS difficulties

GiveLS - amount given in LS difficulty

msgthrow - whether or not pickup message is given via hudmessage, and whether item 
is thrown if actor does not pick it up; see below

Script will return 1 if at least some of the ammo was picked up by the actor, and 0 if not. 

To specify clips and ammo for pistol and ammobox, give # of mags (other than 1) 
in multilples of 1m, bullets in mag in 1k and ammo normally. For instance, to 
give 3 full pistol mags or 50 ammo, give 3015050. To give either 15 ammo or a 
single mag containing 20 ammo, give 20015. If # of mags is ommitted it defaults to 
one. If # of mags is provided but mag amount is ommitted, mag amount defaults to 
full. If this feature isn't used it will behave like mag pickup scripts normally 
do, and either give an ammo amount equal to a typical item or a mag of the 
specified size. 

To have "msgthrow" throw the item if it's not picked up, add 10 to it.
To have "msgthrow" give a pickup message via hudmessage, add 1 to it. 
For instance, 11 would cause both to happen.
Note: Throw not in yet. 

/*//////////////////////////////////////////


//This is down here because it needs above scripts to function.
script "AmmoGiveLS" (int which, int GiveNormal, int GiveLS, int msgthrow) 
{
  int ammogive, ammogive2, maggive, result, nummags;
  int Nmag, Nfmags, Nammo, LSmag, LSfmags, LSammo;

  if(GiveNormal > 1000000){ 
    Nmag = GiveNormal % 1000000;
    Nfmags = (GiveNormal - Nmag) / 1000000;
    if(Nmag > 1000){
      Nammo = Nmag % 1000;
      Nmag = (Nmag - Nammo) / 1000; }
    else{
      Nammo = Nmag;
      Nmag = 0x7FFFFFFF; }}
  else if(GiveNormal > 1000){ 
    Nammo = GiveNormal % 1000;
    Nmag = (GiveNormal - Nammo) / 1000; }
  else{
    Nammo = GiveNormal;
    Nmag = GiveNormal; }

  if(GiveLS > 1000000){ 
    LSmag = GiveLS % 1000000;
    LSfmags = (GiveLS - LSmag) / 1000000;
    if(LSmag > 1000){
      LSammo = LSmag % 1000;
      LSmag = (LSmag - LSammo) / 1000; }
    else{
      LSammo = LSmag;
      LSmag = 0x7FFFFFFF; }}
  else if(GiveLS > 1000){ 
    LSammo = GiveLS % 1000;
    LSmag = (GiveLS - LSammo) / 1000; }
  else{
    LSammo = GiveLS;
    LSmag = GiveLS; }
    
  if(GameSkill() >= 5){ 
    ammogive2 = LSammo;
    maggive = LSmag;
    nummags = LSfmags; }
  else{ 
    ammogive2 = Nammo;
    maggive = Nmag; 
    nummags = Nfmags; }
	
  if(nummags > 1){
    ammogive = ammogive2 / nummags;
    ammogive = ammogive2 - (ammogive * nummags);
    ammogive2 = ammogive2 / nummags; 
    ammogive = ammogive2 + ammogive; }
  else{
    ammogive = ammogive2; }

  switch (which){
    case 2:
      result = ACS_NamedExecuteWithResult("PistolMagPickup",maggive,ammogive,msgthrow);
      while(nummags > 1){
        ACS_NamedExecuteWithResult("PistolMagPickup",maggive,ammogive2,msgthrow);
        --nummags; }
      break;
    case 3:
      result = ACS_NamedExecuteWithResult("ShellPickup",4,ammogive,msgthrow);
      break;
    case 31:
      result = ACS_NamedExecuteWithResult("ShellPickup",1,ammogive,msgthrow);
      break;
    case 32:
      result = ACS_NamedExecuteWithResult("ShellPickup",2,ammogive,msgthrow);
      break;
    case 33:
      result = ACS_NamedExecuteWithResult("ShellPickup",3,ammogive,msgthrow);
      break;
    case 4:
      result = ACS_NamedExecuteWithResult("AB50MagPickup",maggive,ammogive,msgthrow);
      while(nummags > 1){
        ACS_NamedExecuteWithResult("AB50MagPickup",maggive,ammogive2,msgthrow);
        --nummags; }
      break;
    case 41:
      result = ACS_NamedExecuteWithResult("BoltPickup",1,ammogive,msgthrow);
      break;
    case 42:
      result = ACS_NamedExecuteWithResult("BoltPickup",2,ammogive,msgthrow);
      break;
    case 5:
      result = ACS_NamedExecuteWithResult("RocketPickup",ammogive,msgthrow);
      break; }
  setresultvalue(result);
}