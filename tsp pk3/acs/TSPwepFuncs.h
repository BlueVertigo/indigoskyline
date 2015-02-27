//Shotgun Functions

function void ShellMessage(int which, int howmany)
{
  switch(which){
    case 1:
      if(howmany > 1){ hudmessage(s:"Picked up ",d:howmany,s:" \cnshock\c- shells.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up a \cnshock\c- shell.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break;
    case 2:
      if(howmany > 1){ hudmessage(s:"Picked up ",d:howmany,s:" \cihellfire\c- shells.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up a \cihellfire\c- shell.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break;
    case 3:
      if(howmany > 1){ hudmessage(s:"Picked up ",d:howmany,s:" \cppoison\c- shells.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up a \cppoison\c- shell.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break;
    case 4:
      if(howmany > 1){ hudmessage(s:"Picked up ",d:howmany,s:" \cgbuckshot\c- shells.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up a \cgbuckshot\c- shell.";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break; }
}

//Dahlia Functions

function void BoltMessage(int which, int howmany)
{
  switch(which){
    case 1:
      if(howmany > 1){ hudmessage(s:"Picked up a box of crossbow bolts. [\cv+",d:howmany,s:" Crossbow Bolts\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up a crossbow bolt. [\cv+1 Crossbow Bolt\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break;
    case 2:
      if(howmany > 1){ hudmessage(s:"Picked up a box of explosive bolts. [\cj+",d:howmany,s:" Explosive Bolts\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up an explosive bolt. [\cj+1 Explosive Bolt\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break;
    case 3:
      if(howmany > 1){ hudmessage(s:"Picked up a box of crossbow bolts. [\cv+",d:howmany,s:" Crossbow Bolts\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      else{ hudmessage(s:"Picked up a crossbow bolt. [\cv+1 Crossbow Bolt\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
      break; }
}

//ToolBox Functions

function void RocketMessage(int howmany)
{
  if(howmany > 1){ hudmessage(s:"Picked up a crate of Rockets. [\cg+",d:howmany,s:" Launcher Ammo\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
  else{ hudmessage(s:"Picked up a  Rocket. [\cg+1 Launcher Ammo\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
}

//Pistol Functions

function int CountPMags(void)
{
  int ammo;
  ammo = CheckInventory("PMag1");
  ammo = ammo + (CheckInventory("PMag2") * 2);
  ammo = ammo + (CheckInventory("PMag3") * 3);
  ammo = ammo + (CheckInventory("PMag4") * 4);
  ammo = ammo + (CheckInventory("PMag5") * 5);
  ammo = ammo + (CheckInventory("PMag6") * 6);
  ammo = ammo + (CheckInventory("PMag7") * 7);
  ammo = ammo + (CheckInventory("PMag8") * 8);
  ammo = ammo + (CheckInventory("PMag9") * 9);
  ammo = ammo + (CheckInventory("PMag10") * 10);
  ammo = ammo + (CheckInventory("PMag11") * 11);
  ammo = ammo + (CheckInventory("PMag12") * 12);
  ammo = ammo + (CheckInventory("PMag13") * 13);
  ammo = ammo + (CheckInventory("PMag14") * 14);
  ammo = ammo + (CheckInventory("PMag15") * 15);
  return ammo;
}

function int GetSmallestPMag(void)
{
  int smallestmag;
  if(CheckInventory("PMag1")){ smallestmag = 1; }
  else if(CheckInventory("PMag2")){ smallestmag = 2; }
  else if(CheckInventory("PMag3")){ smallestmag = 3; }
  else if(CheckInventory("PMag4")){ smallestmag = 4; }
  else if(CheckInventory("PMag5")){ smallestmag = 5; }
  else if(CheckInventory("PMag6")){ smallestmag = 6; }
  else if(CheckInventory("PMag7")){ smallestmag = 7; }
  else if(CheckInventory("PMag8")){ smallestmag = 8; }
  else if(CheckInventory("PMag9")){ smallestmag = 9; }
  else if(CheckInventory("PMag10")){ smallestmag = 10; }
  else if(CheckInventory("PMag11")){ smallestmag = 11; }
  else if(CheckInventory("PMag12")){ smallestmag = 12; }
  else if(CheckInventory("PMag13")){ smallestmag = 13; }
  else if(CheckInventory("PMag14")){ smallestmag = 14; }
  else if(CheckInventory("PMag15")){ smallestmag = 15; }
  else{ smallestmag = 0; }
  return smallestmag;
}

function int GetLargestPMag(void)
{
  int largestmag;
  if(CheckInventory("PMag15")){ largestmag = 15; }
  else if(CheckInventory("PMag14")){ largestmag = 14; }
  else if(CheckInventory("PMag13")){ largestmag = 13; }
  else if(CheckInventory("PMag12")){ largestmag = 12; }
  else if(CheckInventory("PMag11")){ largestmag = 11; }
  else if(CheckInventory("PMag10")){ largestmag = 10; }
  else if(CheckInventory("PMag9")){ largestmag = 9; }
  else if(CheckInventory("PMag8")){ largestmag = 8; }
  else if(CheckInventory("PMag7")){ largestmag = 7; }
  else if(CheckInventory("PMag6")){ largestmag = 6; }
  else if(CheckInventory("PMag5")){ largestmag = 5; }
  else if(CheckInventory("PMag4")){ largestmag = 4; }
  else if(CheckInventory("PMag3")){ largestmag = 3; }
  else if(CheckInventory("PMag2")){ largestmag = 2; }
  else if(CheckInventory("PMag1")){ largestmag = 1; }
  else{ largestmag = 0; }
  return largestmag;
}

function void GivePMag(int which, int msg, int give)
{
  if(give){ GiveInventory("TSPPistolAmmoMag",1); }
  if(msg && which >= 15){ hudmessage(s:"Picked up a pistol magazine. [\cj+1 Pistol Magazine\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
  else if(msg){ hudmessage(s:"Picked up a used pistol magazine. [\cj+",d:which,s:" Pistol Ammo\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
  switch(which){
    case 1:
      GiveInventory("PMag1",1);
      break;
    case 2:
      GiveInventory("PMag2",1);
      break;
    case 3:
      GiveInventory("PMag3",1);
      break;
    case 4:
      GiveInventory("PMag4",1);
      break;
    case 5:
      GiveInventory("PMag5",1);
      break;
    case 6:
      GiveInventory("PMag6",1);
      break;
    case 7:
      GiveInventory("PMag7",1);
      break;
    case 8:
      GiveInventory("PMag8",1);
      break;
    case 9:
      GiveInventory("PMag9",1);
      break;
    case 10:
      GiveInventory("PMag10",1);
      break;
    case 11:
      GiveInventory("PMag11",1);
      break;
    case 12:
      GiveInventory("PMag12",1);
      break;
    case 13:
      GiveInventory("PMag13",1);
      break;
    case 14:
      GiveInventory("PMag14",1);
      break;
    case 15:
      GiveInventory("PMag15",1);
      break; }
}

function void TakePMag(int which, int throw, int take)
{
  if(take){ TakeInventory("TSPPistolAmmoMag",1); }
  switch(which){
    case 0:
      if(throw){ GiveInventory("BaseThrowPMag",1); }
      break;
    case 1:
      TakeInventory("PMag1",1);
      if(throw){ GiveInventory("ThrowPMag1",1); }
      break;
    case 2:
      TakeInventory("PMag2",1);
      if(throw){ GiveInventory("ThrowPMag2",1); }
      break;
    case 3:
      TakeInventory("PMag3",1);
      if(throw){ GiveInventory("ThrowPMag3",1); }
      break;
    case 4:
      TakeInventory("PMag4",1);
      if(throw){ GiveInventory("ThrowPMag4",1); }
      break;
    case 5:
      TakeInventory("PMag5",1);
      if(throw){ GiveInventory("ThrowPMag5",1); }
      break;
    case 6:
      TakeInventory("PMag6",1);
      if(throw){ GiveInventory("ThrowPMag6",1); }
      break;
    case 7:
      TakeInventory("PMag7",1);
      if(throw){ GiveInventory("ThrowPMag7",1); }
      break;
    case 8:
      TakeInventory("PMag8",1);
      if(throw){ GiveInventory("ThrowPMag8",1); }
      break;
    case 9:
      TakeInventory("PMag9",1);
      if(throw){ GiveInventory("ThrowPMag9",1); }
      break;
    case 10:
      TakeInventory("PMag10",1);
      if(throw){ GiveInventory("ThrowPMag10",1); }
      break;
    case 11:
      TakeInventory("PMag11",1);
      if(throw){ GiveInventory("ThrowPMag11",1); }
      break;
    case 12:
      TakeInventory("PMag12",1);
      if(throw){ GiveInventory("ThrowPMag12",1); }
      break;
    case 13:
      TakeInventory("PMag13",1);
      if(throw){ GiveInventory("ThrowPMag13",1); }
      break;
    case 14:
      TakeInventory("PMag14",1);
      if(throw){ GiveInventory("ThrowPMag14",1); }
      break;
    case 15:
      TakeInventory("PMag15",1);
      if(throw){ GiveInventory("ThrowPMag15",1); }
      break; }
}

function void ClearPMags(int take)
{
  if(take){ TakeInventory("TSPPistolAmmoMag",0x7FFFFFFF); }
  TakeInventory("PMag1",0x7FFFFFFF);
  TakeInventory("PMag2",0x7FFFFFFF);
  TakeInventory("PMag3",0x7FFFFFFF);
  TakeInventory("PMag4",0x7FFFFFFF);
  TakeInventory("PMag5",0x7FFFFFFF);
  TakeInventory("PMag6",0x7FFFFFFF);
  TakeInventory("PMag7",0x7FFFFFFF);
  TakeInventory("PMag8",0x7FFFFFFF);
  TakeInventory("PMag9",0x7FFFFFFF);
  TakeInventory("PMag10",0x7FFFFFFF);
  TakeInventory("PMag11",0x7FFFFFFF);
  TakeInventory("PMag12",0x7FFFFFFF);
  TakeInventory("PMag13",0x7FFFFFFF);
  TakeInventory("PMag14",0x7FFFFFFF);
  TakeInventory("PMag15",0x7FFFFFFF);
}

//Ammobox-50 Functions

function int CountAMags(void)
{
  int ammo;
  ammo = CheckInventory("AMag1");
  ammo = ammo + (CheckInventory("AMag2") * 2);
  ammo = ammo + (CheckInventory("AMag3") * 3);
  ammo = ammo + (CheckInventory("AMag4") * 4);
  ammo = ammo + (CheckInventory("AMag5") * 5);
  ammo = ammo + (CheckInventory("AMag6") * 6);
  ammo = ammo + (CheckInventory("AMag7") * 7);
  ammo = ammo + (CheckInventory("AMag8") * 8);
  ammo = ammo + (CheckInventory("AMag9") * 9);
  ammo = ammo + (CheckInventory("AMag10") * 10);
  ammo = ammo + (CheckInventory("AMag11") * 11);
  ammo = ammo + (CheckInventory("AMag12") * 12);
  ammo = ammo + (CheckInventory("AMag13") * 13);
  ammo = ammo + (CheckInventory("AMag14") * 14);
  ammo = ammo + (CheckInventory("AMag15") * 15);
  ammo = ammo + (CheckInventory("AMag16") * 16);
  ammo = ammo + (CheckInventory("AMag17") * 17);
  ammo = ammo + (CheckInventory("AMag18") * 18);
  ammo = ammo + (CheckInventory("AMag19") * 19);
  ammo = ammo + (CheckInventory("AMag20") * 20);
  ammo = ammo + (CheckInventory("AMag21") * 21);
  ammo = ammo + (CheckInventory("AMag22") * 22);
  ammo = ammo + (CheckInventory("AMag23") * 23);
  ammo = ammo + (CheckInventory("AMag24") * 24);
  ammo = ammo + (CheckInventory("AMag25") * 25);
  ammo = ammo + (CheckInventory("AMag26") * 26);
  ammo = ammo + (CheckInventory("AMag27") * 27);
  ammo = ammo + (CheckInventory("AMag28") * 28);
  ammo = ammo + (CheckInventory("AMag29") * 29);
  ammo = ammo + (CheckInventory("AMag30") * 30);
  ammo = ammo + (CheckInventory("AMag31") * 31);
  ammo = ammo + (CheckInventory("AMag32") * 32);
  ammo = ammo + (CheckInventory("AMag33") * 33);
  ammo = ammo + (CheckInventory("AMag34") * 34);
  ammo = ammo + (CheckInventory("AMag35") * 35);
  ammo = ammo + (CheckInventory("AMag36") * 36);
  ammo = ammo + (CheckInventory("AMag37") * 37);
  ammo = ammo + (CheckInventory("AMag38") * 38);
  ammo = ammo + (CheckInventory("AMag39") * 39);
  ammo = ammo + (CheckInventory("AMag40") * 40);
  ammo = ammo + (CheckInventory("AMag41") * 41);
  ammo = ammo + (CheckInventory("AMag42") * 42);
  ammo = ammo + (CheckInventory("AMag43") * 43);
  ammo = ammo + (CheckInventory("AMag44") * 44);
  ammo = ammo + (CheckInventory("AMag45") * 45);
  ammo = ammo + (CheckInventory("AMag46") * 46);
  ammo = ammo + (CheckInventory("AMag47") * 47);
  ammo = ammo + (CheckInventory("AMag48") * 48);
  ammo = ammo + (CheckInventory("AMag49") * 49);
  ammo = ammo + (CheckInventory("AMag50") * 50);
  return ammo;
}

function int GetSmallestAMag(void)
{
  int smallestmag;
  if(CheckInventory("AMag1")){ smallestmag = 1; }
  else if(CheckInventory("AMag2")){ smallestmag = 2; }
  else if(CheckInventory("AMag3")){ smallestmag = 3; }
  else if(CheckInventory("AMag4")){ smallestmag = 4; }
  else if(CheckInventory("AMag5")){ smallestmag = 5; }
  else if(CheckInventory("AMag6")){ smallestmag = 6; }
  else if(CheckInventory("AMag7")){ smallestmag = 7; }
  else if(CheckInventory("AMag8")){ smallestmag = 8; }
  else if(CheckInventory("AMag9")){ smallestmag = 9; }
  else if(CheckInventory("AMag10")){ smallestmag = 10; }
  else if(CheckInventory("AMag11")){ smallestmag = 11; }
  else if(CheckInventory("AMag12")){ smallestmag = 12; }
  else if(CheckInventory("AMag13")){ smallestmag = 13; }
  else if(CheckInventory("AMag14")){ smallestmag = 14; }
  else if(CheckInventory("AMag15")){ smallestmag = 15; }
  else if(CheckInventory("AMag16")){ smallestmag = 16; }
  else if(CheckInventory("AMag17")){ smallestmag = 17; }
  else if(CheckInventory("AMag18")){ smallestmag = 18; }
  else if(CheckInventory("AMag19")){ smallestmag = 19; }
  else if(CheckInventory("AMag20")){ smallestmag = 20; }
  else if(CheckInventory("AMag21")){ smallestmag = 21; }
  else if(CheckInventory("AMag22")){ smallestmag = 22; }
  else if(CheckInventory("AMag23")){ smallestmag = 23; }
  else if(CheckInventory("AMag24")){ smallestmag = 24; }
  else if(CheckInventory("AMag25")){ smallestmag = 25; }
  else if(CheckInventory("AMag26")){ smallestmag = 26; }
  else if(CheckInventory("AMag27")){ smallestmag = 27; }
  else if(CheckInventory("AMag28")){ smallestmag = 28; }
  else if(CheckInventory("AMag29")){ smallestmag = 29; }
  else if(CheckInventory("AMag30")){ smallestmag = 30; }
  else if(CheckInventory("AMag31")){ smallestmag = 31; }
  else if(CheckInventory("AMag32")){ smallestmag = 32; }
  else if(CheckInventory("AMag33")){ smallestmag = 33; }
  else if(CheckInventory("AMag34")){ smallestmag = 34; }
  else if(CheckInventory("AMag35")){ smallestmag = 35; }
  else if(CheckInventory("AMag36")){ smallestmag = 36; }
  else if(CheckInventory("AMag37")){ smallestmag = 37; }
  else if(CheckInventory("AMag38")){ smallestmag = 38; }
  else if(CheckInventory("AMag39")){ smallestmag = 39; }
  else if(CheckInventory("AMag40")){ smallestmag = 40; }
  else if(CheckInventory("AMag41")){ smallestmag = 41; }
  else if(CheckInventory("AMag42")){ smallestmag = 42; }
  else if(CheckInventory("AMag43")){ smallestmag = 43; }
  else if(CheckInventory("AMag44")){ smallestmag = 44; }
  else if(CheckInventory("AMag45")){ smallestmag = 45; }
  else if(CheckInventory("AMag46")){ smallestmag = 46; }
  else if(CheckInventory("AMag47")){ smallestmag = 47; }
  else if(CheckInventory("AMag48")){ smallestmag = 48; }
  else if(CheckInventory("AMag49")){ smallestmag = 49; }
  else if(CheckInventory("AMag50")){ smallestmag = 50; }
  else{ smallestmag = 0; }
  return smallestmag;
}

function int GetLargestAMag(void)
{
  int largestmag;
  if(CheckInventory("AMag50")){ largestmag = 50; }
  else if(CheckInventory("AMag49")){ largestmag = 49; }
  else if(CheckInventory("AMag48")){ largestmag = 48; }
  else if(CheckInventory("AMag47")){ largestmag = 47; }
  else if(CheckInventory("AMag46")){ largestmag = 46; }
  else if(CheckInventory("AMag45")){ largestmag = 45; }
  else if(CheckInventory("AMag44")){ largestmag = 44; }
  else if(CheckInventory("AMag43")){ largestmag = 43; }
  else if(CheckInventory("AMag42")){ largestmag = 42; }
  else if(CheckInventory("AMag41")){ largestmag = 41; }
  else if(CheckInventory("AMag40")){ largestmag = 40; }
  else if(CheckInventory("AMag39")){ largestmag = 39; }
  else if(CheckInventory("AMag38")){ largestmag = 38; }
  else if(CheckInventory("AMag37")){ largestmag = 37; }
  else if(CheckInventory("AMag36")){ largestmag = 36; }
  else if(CheckInventory("AMag35")){ largestmag = 35; }
  else if(CheckInventory("AMag34")){ largestmag = 34; }
  else if(CheckInventory("AMag33")){ largestmag = 33; }
  else if(CheckInventory("AMag32")){ largestmag = 32; }
  else if(CheckInventory("AMag31")){ largestmag = 31; }
  else if(CheckInventory("AMag30")){ largestmag = 30; }
  else if(CheckInventory("AMag29")){ largestmag = 29; }
  else if(CheckInventory("AMag28")){ largestmag = 28; }
  else if(CheckInventory("AMag27")){ largestmag = 27; }
  else if(CheckInventory("AMag26")){ largestmag = 26; }
  else if(CheckInventory("AMag25")){ largestmag = 25; }
  else if(CheckInventory("AMag24")){ largestmag = 24; }
  else if(CheckInventory("AMag23")){ largestmag = 23; }
  else if(CheckInventory("AMag22")){ largestmag = 22; }
  else if(CheckInventory("AMag21")){ largestmag = 21; }
  else if(CheckInventory("AMag20")){ largestmag = 20; }
  else if(CheckInventory("AMag19")){ largestmag = 19; }
  else if(CheckInventory("AMag18")){ largestmag = 18; }
  else if(CheckInventory("AMag17")){ largestmag = 17; }
  else if(CheckInventory("AMag16")){ largestmag = 16; }
  else if(CheckInventory("AMag15")){ largestmag = 15; }
  else if(CheckInventory("AMag14")){ largestmag = 14; }
  else if(CheckInventory("AMag13")){ largestmag = 13; }
  else if(CheckInventory("AMag12")){ largestmag = 12; }
  else if(CheckInventory("AMag11")){ largestmag = 11; }
  else if(CheckInventory("AMag10")){ largestmag = 10; }
  else if(CheckInventory("AMag9")){ largestmag = 9; }
  else if(CheckInventory("AMag8")){ largestmag = 8; }
  else if(CheckInventory("AMag7")){ largestmag = 7; }
  else if(CheckInventory("AMag6")){ largestmag = 6; }
  else if(CheckInventory("AMag5")){ largestmag = 5; }
  else if(CheckInventory("AMag4")){ largestmag = 4; }
  else if(CheckInventory("AMag3")){ largestmag = 3; }
  else if(CheckInventory("AMag2")){ largestmag = 2; }
  else if(CheckInventory("AMag1")){ largestmag = 1; }
  else{ largestmag = 0; }
  return largestmag;
}

function void GiveAMag(int which, int msg, int give)
{
  if(give){ GiveInventory("AmmoBoxAmmoMag",1); }
  if(msg && which >= 50){ hudmessage(s:"Picked up a full SMG magazine. [\cj+1 SMG Magazine\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
  else if(msg){ hudmessage(s:"Picked up a used SMG magazine. [\cj+",d:which,s:" SMG Ammo\c-]";HUDMSG_PLAIN|HUDMSG_LOG,2,CR_RED,0.0,0.0,1.0); }
  switch(which){
    case 1:
      GiveInventory("AMag1",1);
      break;
    case 2:
      GiveInventory("AMag2",1);
      break;
    case 3:
      GiveInventory("AMag3",1);
      break;
    case 4:
      GiveInventory("AMag4",1);
      break;
    case 5:
      GiveInventory("AMag5",1);
      break;
    case 6:
      GiveInventory("AMag6",1);
      break;
    case 7:
      GiveInventory("AMag7",1);
      break;
    case 8:
      GiveInventory("AMag8",1);
      break;
    case 9:
      GiveInventory("AMag9",1);
      break;
    case 10:
      GiveInventory("AMag10",1);
      break;
    case 11:
      GiveInventory("AMag11",1);
      break;
    case 12:
      GiveInventory("AMag12",1);
      break;
    case 13:
      GiveInventory("AMag13",1);
      break;
    case 14:
      GiveInventory("AMag14",1);
      break;
    case 15:
      GiveInventory("AMag15",1);
      break;
    case 16:
      GiveInventory("AMag16",1);
      break;
    case 17:
      GiveInventory("AMag17",1);
      break;
    case 18:
      GiveInventory("AMag18",1);
      break;
    case 19:
      GiveInventory("AMag19",1);
      break;
    case 20:
      GiveInventory("AMag20",1);
      break;
    case 21:
      GiveInventory("AMag21",1);
      break;
    case 22:
      GiveInventory("AMag22",1);
      break;
    case 23:
      GiveInventory("AMag23",1);
      break;
    case 24:
      GiveInventory("AMag24",1);
      break;
    case 25:
      GiveInventory("AMag25",1);
      break;
    case 26:
      GiveInventory("AMag26",1);
      break;
    case 27:
      GiveInventory("AMag27",1);
      break;
    case 28:
      GiveInventory("AMag28",1);
      break;
    case 29:
      GiveInventory("AMag29",1);
      break;
    case 30:
      GiveInventory("AMag30",1);
      break;
    case 31:
      GiveInventory("AMag31",1);
      break;
    case 32:
      GiveInventory("AMag32",1);
      break;
    case 33:
      GiveInventory("AMag33",1);
      break;
    case 34:
      GiveInventory("AMag34",1);
      break;
    case 35:
      GiveInventory("AMag35",1);
      break;
    case 36:
      GiveInventory("AMag36",1);
      break;
    case 37:
      GiveInventory("AMag37",1);
      break;
    case 38:
      GiveInventory("AMag38",1);
      break;
    case 39:
      GiveInventory("AMag39",1);
      break;
    case 40:
      GiveInventory("AMag40",1);
      break;
    case 41:
      GiveInventory("AMag41",1);
      break;
    case 42:
      GiveInventory("AMag42",1);
      break;
    case 43:
      GiveInventory("AMag43",1);
      break;
    case 44:
      GiveInventory("AMag44",1);
      break;
    case 45:
      GiveInventory("AMag45",1);
      break;
    case 46:
      GiveInventory("AMag46",1);
      break;
    case 47:
      GiveInventory("AMag47",1);
      break;
    case 48:
      GiveInventory("AMag48",1);
      break;
    case 49:
      GiveInventory("AMag49",1);
      break;
    case 50:
      GiveInventory("AMag50",1);
      break;}
}

function void TakeAMag(int which, int throw, int take)
{
  if(take){ TakeInventory("AmmoBoxAmmoMag",1); }
  switch(which){
    case 0:
      if(throw){ GiveInventory("BaseThrowAMag",1); }
      break;
    case 1:
      TakeInventory("AMag1",1);
      if(throw){ GiveInventory("ThrowAMag1",1); }
      break;
    case 2:
      TakeInventory("AMag2",1);
      if(throw){ GiveInventory("ThrowAMag2",1); }
      break;
    case 3:
      TakeInventory("AMag3",1);
      if(throw){ GiveInventory("ThrowAMag3",1); }
      break;
    case 4:
      TakeInventory("AMag4",1);
      if(throw){ GiveInventory("ThrowAMag4",1); }
      break;
    case 5:
      TakeInventory("AMag5",1);
      if(throw){ GiveInventory("ThrowAMag5",1); }
      break;
    case 6:
      TakeInventory("AMag6",1);
      if(throw){ GiveInventory("ThrowAMag6",1); }
      break;
    case 7:
      TakeInventory("AMag7",1);
      if(throw){ GiveInventory("ThrowAMag7",1); }
      break;
    case 8:
      TakeInventory("AMag8",1);
      if(throw){ GiveInventory("ThrowAMag8",1); }
      break;
    case 9:
      TakeInventory("AMag9",1);
      if(throw){ GiveInventory("ThrowAMag9",1); }
      break;
    case 10:
      TakeInventory("AMag10",1);
      if(throw){ GiveInventory("ThrowAMag10",1); }
      break;
    case 11:
      TakeInventory("AMag11",1);
      if(throw){ GiveInventory("ThrowAMag11",1); }
      break;
    case 12:
      TakeInventory("AMag12",1);
      if(throw){ GiveInventory("ThrowAMag12",1); }
      break;
    case 13:
      TakeInventory("AMag13",1);
      if(throw){ GiveInventory("ThrowAMag13",1); }
      break;
    case 14:
      TakeInventory("AMag14",1);
      if(throw){ GiveInventory("ThrowAMag14",1); }
      break;
    case 15:
      TakeInventory("AMag15",1);
      if(throw){ GiveInventory("ThrowAMag15",1); }
      break;
    case 16:
      TakeInventory("AMag16",1);
      if(throw){ GiveInventory("ThrowAMag16",1); }
      break;
    case 17:
      TakeInventory("AMag17",1);
      if(throw){ GiveInventory("ThrowAMag17",1); }
      break;
    case 18:
      TakeInventory("AMag18",1);
      if(throw){ GiveInventory("ThrowAMag18",1); }
      break;
    case 19:
      TakeInventory("AMag19",1);
      if(throw){ GiveInventory("ThrowAMag19",1); }
      break;
    case 20:
      TakeInventory("AMag20",1);
      if(throw){ GiveInventory("ThrowAMag20",1); }
      break;
    case 21:
      TakeInventory("AMag21",1);
      if(throw){ GiveInventory("ThrowAMag21",1); }
      break;
    case 22:
      TakeInventory("AMag22",1);
      if(throw){ GiveInventory("ThrowAMag22",1); }
      break;
    case 23:
      TakeInventory("AMag23",1);
      if(throw){ GiveInventory("ThrowAMag23",1); }
      break;
    case 24:
      TakeInventory("AMag24",1);
      if(throw){ GiveInventory("ThrowAMag24",1); }
      break;
    case 25:
      TakeInventory("AMag25",1);
      if(throw){ GiveInventory("ThrowAMag25",1); }
      break;
    case 26:
      TakeInventory("AMag26",1);
      if(throw){ GiveInventory("ThrowAMag26",1); }
      break;
    case 27:
      TakeInventory("AMag27",1);
      if(throw){ GiveInventory("ThrowAMag27",1); }
      break;
    case 28:
      TakeInventory("AMag28",1);
      if(throw){ GiveInventory("ThrowAMag28",1); }
      break;
    case 29:
      TakeInventory("AMag29",1);
      if(throw){ GiveInventory("ThrowAMag29",1); }
      break;
    case 30:
      TakeInventory("AMag30",1);
      if(throw){ GiveInventory("ThrowAMag30",1); }
      break;
    case 31:
      TakeInventory("AMag31",1);
      if(throw){ GiveInventory("ThrowAMag31",1); }
      break;
    case 32:
      TakeInventory("AMag32",1);
      if(throw){ GiveInventory("ThrowAMag32",1); }
      break;
    case 33:
      TakeInventory("AMag33",1);
      if(throw){ GiveInventory("ThrowAMag33",1); }
      break;
    case 34:
      TakeInventory("AMag34",1);
      if(throw){ GiveInventory("ThrowAMag34",1); }
      break;
    case 35:
      TakeInventory("AMag35",1);
      if(throw){ GiveInventory("ThrowAMag35",1); }
      break;
    case 36:
      TakeInventory("AMag36",1);
      if(throw){ GiveInventory("ThrowAMag36",1); }
      break;
    case 37:
      TakeInventory("AMag37",1);
      if(throw){ GiveInventory("ThrowAMag37",1); }
      break;
    case 38:
      TakeInventory("AMag38",1);
      if(throw){ GiveInventory("ThrowAMag38",1); }
      break;
    case 39:
      TakeInventory("AMag39",1);
      if(throw){ GiveInventory("ThrowAMag39",1); }
      break;
    case 40:
      TakeInventory("AMag40",1);
      if(throw){ GiveInventory("ThrowAMag40",1); }
      break;
    case 41:
      TakeInventory("AMag41",1);
      if(throw){ GiveInventory("ThrowAMag41",1); }
      break;
    case 42:
      TakeInventory("AMag42",1);
      if(throw){ GiveInventory("ThrowAMag42",1); }
      break;
    case 43:
      TakeInventory("AMag43",1);
      if(throw){ GiveInventory("ThrowAMag43",1); }
      break;
    case 44:
      TakeInventory("AMag44",1);
      if(throw){ GiveInventory("ThrowAMag44",1); }
      break;
    case 45:
      TakeInventory("AMag45",1);
      if(throw){ GiveInventory("ThrowAMag45",1); }
      break;
    case 46:
      TakeInventory("AMag46",1);
      if(throw){ GiveInventory("ThrowAMag46",1); }
      break;
    case 47:
      TakeInventory("AMag47",1);
      if(throw){ GiveInventory("ThrowAMag47",1); }
      break;
    case 48:
      TakeInventory("AMag48",1);
      if(throw){ GiveInventory("ThrowAMag48",1); }
      break;
    case 49:
      TakeInventory("AMag49",1);
      if(throw){ GiveInventory("ThrowAMag49",1); }
      break;
    case 50:
      TakeInventory("AMag50",1);
      if(throw){ GiveInventory("ThrowAMag50",1); }
      break; }
}

function void ClearAMags(int take)
{
  if(take){ TakeInventory("AmmoBoxAmmoMag",0x7FFFFFFF); }
  TakeInventory("AMag1",0x7FFFFFFF);
  TakeInventory("AMag2",0x7FFFFFFF);
  TakeInventory("AMag3",0x7FFFFFFF);
  TakeInventory("AMag4",0x7FFFFFFF);
  TakeInventory("AMag5",0x7FFFFFFF);
  TakeInventory("AMag6",0x7FFFFFFF);
  TakeInventory("AMag7",0x7FFFFFFF);
  TakeInventory("AMag8",0x7FFFFFFF);
  TakeInventory("AMag9",0x7FFFFFFF);
  TakeInventory("AMag10",0x7FFFFFFF);
  TakeInventory("AMag11",0x7FFFFFFF);
  TakeInventory("AMag12",0x7FFFFFFF);
  TakeInventory("AMag13",0x7FFFFFFF);
  TakeInventory("AMag14",0x7FFFFFFF);
  TakeInventory("AMag15",0x7FFFFFFF);
  TakeInventory("AMag16",0x7FFFFFFF);
  TakeInventory("AMag17",0x7FFFFFFF);
  TakeInventory("AMag18",0x7FFFFFFF);
  TakeInventory("AMag19",0x7FFFFFFF);
  TakeInventory("AMag20",0x7FFFFFFF);
  TakeInventory("AMag21",0x7FFFFFFF);
  TakeInventory("AMag22",0x7FFFFFFF);
  TakeInventory("AMag23",0x7FFFFFFF);
  TakeInventory("AMag24",0x7FFFFFFF);
  TakeInventory("AMag25",0x7FFFFFFF);
  TakeInventory("AMag26",0x7FFFFFFF);
  TakeInventory("AMag27",0x7FFFFFFF);
  TakeInventory("AMag28",0x7FFFFFFF);
  TakeInventory("AMag29",0x7FFFFFFF);
  TakeInventory("AMag30",0x7FFFFFFF);
  TakeInventory("AMag31",0x7FFFFFFF);
  TakeInventory("AMag32",0x7FFFFFFF);
  TakeInventory("AMag33",0x7FFFFFFF);
  TakeInventory("AMag34",0x7FFFFFFF);
  TakeInventory("AMag35",0x7FFFFFFF);
  TakeInventory("AMag36",0x7FFFFFFF);
  TakeInventory("AMag37",0x7FFFFFFF);
  TakeInventory("AMag38",0x7FFFFFFF);
  TakeInventory("AMag39",0x7FFFFFFF);
  TakeInventory("AMag40",0x7FFFFFFF);
  TakeInventory("AMag41",0x7FFFFFFF);
  TakeInventory("AMag42",0x7FFFFFFF);
  TakeInventory("AMag43",0x7FFFFFFF);
  TakeInventory("AMag44",0x7FFFFFFF);
  TakeInventory("AMag45",0x7FFFFFFF);
  TakeInventory("AMag46",0x7FFFFFFF);
  TakeInventory("AMag47",0x7FFFFFFF);
  TakeInventory("AMag48",0x7FFFFFFF);
  TakeInventory("AMag49",0x7FFFFFFF);
  TakeInventory("AMag50",0x7FFFFFFF);
}