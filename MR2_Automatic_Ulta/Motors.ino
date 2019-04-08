void walk(byte tl = speedTL, byte tr = speedTR, byte bl = speedBL, byte br = speedBR) {
  if(tl != prevTL)  analogWrite(mTLp, tl);
  if(tr != prevTR)  analogWrite(mTRp, tr);
  if(bl != prevBL)  analogWrite(mBLp, bl);
  if(br != prevBR)  analogWrite(mBRp, br);

  prevTL = tl;
  prevTR = tr;
  prevBL = bl;
  prevBR = br; 
}

void stop() {
  analogWrite(mTLp, 0);
  analogWrite(mTRp, 0);
  analogWrite(mBLp, 0);
  analogWrite(mBRp, 0);
}
