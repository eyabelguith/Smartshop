    #include "ESPino32CAM.h"
#include "ESPino32CAM_QRCode.h"

ESPino32CAM cam;
ESPino32QRCode qr;
#define BUTTON_QR 0
#define CAMERA_MODEL_AI_THINKER
 
// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
 
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1500) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 500)  return btnLEFT; 
 if (adc_key_in < 700)  return btnSELECT;   
 return btnNONE;  // when all others fail, return this...
}

void setup() {
  Serial.begin(115200);
  Serial.println("\r\nESPino32CAM");
  if (cam.init() != ESP_OK)
  {
    Serial.println(F("Fail"));
    while (1);
  }
  qr.init(&cam);
  sensor_t *s = cam.sensor();
  s->set_framesize(s, FRAMESIZE_VGA);
  s->set_whitebal(s,true);
  
  
}
void loop()
{
  camera_fb_t *fb = cam.capture();
  if (!fb)
  {
    Serial.println("Camera capture failed");
    return;
  }
  
  //Serial.write(fb->buf, fb->len);
  dl_matrix3du_t *image_rgb;
  if(cam.jpg2rgb(fb,&image_rgb))
  {
     cam.clearMemory(fb);
     if(!digitalRead(BUTTON_QR))
     {
        //cam.printDebug("\r\nQR Read:");
        qrResoult res = qr.recognition(image_rgb);
       if(res.status)
       {  Serial.println(res.payload);
          
          /* cam.printDebug("");
          cam.printfDebug("Version: %d", res.version);
          cam.printfDebug("ECC level: %c",res.eccLevel);
          cam.printfDebug("Mask: %d", res.mask);
          cam.printDebug("Data type: "+ qr.dataType(res.dataType));
          cam.printfDebug("Length: %d",res.length);
          cam.printDebug("Payload: "+res.payload); */ 
       }
       else int x=0;
          //cam.printDebug("FAIL");
     }
  }
  cam.clearMemory(image_rgb);  
}
