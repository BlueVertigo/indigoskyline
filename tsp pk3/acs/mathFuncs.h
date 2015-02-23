function int arcsin(int x)
{
  return VectorAngle(FixedSqrt(1.0 - FixedMul(x,x)), x);
}

function int arccos(int x)
{
  return VectorAngle(x, FixedSqrt(1.0 - FixedMul(x,x)));
}

function int arctan(int x)
{
  return VectorAngle(1.0, x);
}

function int sq(int x)
{
  return FixedMul(x, x);
}

function int t_ang(int x)
{
  return abs(x % 0.5);
}

/* This is probably less efficient than Thing_ProjectileIntercept, but I don't 
know C++ and so can't copy the code it uses, so whatever. I got the idea to 
use law of sines from the comments in P_Thing_Projectile in p_things.cpp @ the 
ZDoom git (https://github.com/rheit/zdoom/blob/master/src/p_things.cpp) */

function int ProjectileIntercept(int stid, int ttid, int speed, int ptid)
{
  int t;

  int sX = GetActorX(stid);
  int sY = GetActorY(stid);
  int sZ = GetActorZ(stid);

  int tX = GetActorX(ttid);
  int tY = GetActorY(ttid);
  int tZ = GetActorZ(ttid);

  int tVelX = GetActorVelX(ttid);
  int tVelY = GetActorVelY(ttid);
  int tVelZ = GetActorVelZ(ttid);

  int T_S_z = tZ - sZ;
  int TSz_d = abs(T_S_z);
  int S_T_Pdis = abs(VectorLength(sX - tX, sY - tY));
  int S_T_Ang = VectorAngle(tX - sX, tY - sY);
  int T_S_Ang = VectorAngle(sX - tX, sY - tY);
  int S_T_Tf_Ang = t_ang( VectorAngle(tVelX, tVelY) - T_S_Ang );
  
  
  int S_T_Pdis_t = FixedMul(t,S_T_Pdis);
  int tVelX_t = FixedMul(t,tVelX);
  int tVelY_t = FixedMul(t,tVelY);
  int tVelZ_t = FixedMul(t,tVelZ);
  int tXf = tX + tVelX_t;
  int tYf = tY + tVelY_t;
  int tZf = tZ + tVelZ_t;
  
  int XY_spd_t = FixedSqrt(sq(FixedMul(t,spd)) - sq(FixedDiv((T_S_z + tVelZ_t), t)));

  int = T_S_Tf_Ang = t_ang( VectorAngle(tXf - sX, tYf - sX) - S_T_Ang );

  int tSfT = (S_T_Pdis_t / sin(T_S_Tf_Ang)) * sin(S_T_Tf_Ang);
  
  int diff = tS_fT - XY_spd_t;
    


















