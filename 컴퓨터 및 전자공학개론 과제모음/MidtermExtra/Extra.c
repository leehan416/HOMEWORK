int N = 0;
int v = 0;
byte data;
void setup() {
    pinMode(13, OUTPUT);            
    Serial.begin(9600); 
}

void loop() {
    if (Serial.available() > 0) {
        data = Serial.read(); 
        N = (data - 48);
        if ((N  > 1) && (N <= 9)) {
            for (int i = 0;;) {
                i++;
                if (i <= N) {
                    for (int j = 1; j < 10; j++) {
                        v = i * j;
                        Serial.print(i);
                        Serial.print(" * ");
                        Serial.print(j);
                        Serial.print(" = ");
                        Serial.print(v);
                        Serial.print(" ");
                    }
                    Serial.println(" ");
                } else { 
                    return;
                }
            }
        } else {
            Serial.println("Error Input");
            return;
        }
    }
}
