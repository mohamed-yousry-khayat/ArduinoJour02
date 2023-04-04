void ledRVBpwm(int pwmRouge, int pwmVert, int pwmBleu);
const int ledRouge=6;
const int ledVert=3; 
const int ledBleu=5; 
int tension, val;
void setup() {
pinMode (ledVert,OUTPUT);
pinMode (ledRouge,OUTPUT);
pinMode (ledBleu,OUTPUT);
}
void loop(){
tension = analogRead(A0);
val = map(tension,0,1023,0,2*255);
if( val < 255)
ledRVBpwm(0,val,255-val);
if( val >= 255 && val <= 2*255)
ledRVBpwm(val-255, 255-(val-255),0);
}
void ledRVBpwm(int pwmRouge, int pwmVert, int pwmBleu) {
analogWrite(ledRouge, pwmRouge);
analogWrite(ledVert, pwmVert);
analogWrite(ledBleu, pwmBleu);
}