void setup()
{
  Serial.begin(9600);
}

void loop()
{
  pinMode(A1, INPUT);
  int pinA1 = analogRead(A1) ;
  double VA1 = ( ( pinA1 * 5.00 ) / 1024 ) ;
  double Rpt1000 = ( 1000 * (  VA1 / ( 5.00 - VA1 )) ) ;
  double T = ( ( Rpt1000 - 1000 ) / 3.85 ) ;
  Serial.print("La temperatura medida en grados centgrados es: ");
  Serial.print(T);
  Serial.println();
  delay( 10000 );
}
