const uint32_t wakeup = 20 * 1000000; 

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");
  delay(10000);
  hibernate();
}

void lightSleep() {
    Serial.println("Light mode starting...");
    Serial.flush();
    
    esp_sleep_enable_timer_wakeup(wakeup);
    esp_light_sleep_start();

    Serial.print("exiting light sleep");
    while(1)
    {

    }
}

void deepSleep() {
    Serial.println("Deep sleep starting...");
    Serial.flush();

    esp_sleep_enable_timer_wakeup(wakeup);
    esp_deep_sleep_start();
}

void hibernate() {
    Serial.println("hibernating...");
    Serial.flush();

    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH,   ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_FAST_MEM, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_XTAL,         ESP_PD_OPTION_OFF);
    
    esp_sleep_enable_timer_wakeup(wakeup);
    deepSleep();
}

void loop() {

}