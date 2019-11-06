/*
 * 
 * 
 * 
 *                        FICHIER DE CONFIGURATION SENSOR TEMPERATURE_HUMIDITE
 * 
 * 
 */




// ---------- CARACTERISTIQUE CAPTEUR ----------------
#define PIN_SENSOR_TEMP_HUM A0


#define DHTTYPE DHT11
#define ACTION_TEMP 27
#define ACTION_HUM 80



int weather(float temp, float hum);
