
void ConnectWiFi()
{
  Serial.println("ConnectWiFi");  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(ip, gateway, subnet);
  delay(100);
}
void ConnectWiFi_AP(bool useStaticIP = false)
{ 
   Serial.println("ConnectWiFi_AP");
   WiFi.mode(WIFI_AP);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(100);
   }
   if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

   Serial.println("");
   Serial.print("Iniciado AP:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.softAPIP());
}

void ConnectWiFi_STA(bool useStaticIP = false)
{
   Serial.println("ConnectWiFi_STA");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(useStaticIP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Iniciado STA:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
}
