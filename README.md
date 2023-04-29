This repository is "Body interface project" by shiwasu_tech since 2023/04/23

# Body Interface

1. Facial Play/Pause

**"Have you ever felt annoying to stop the movie and retake a pen again when you watch class videos and need to take some memos?"**
This project help you act so without stress.

When your face is UP, nothing happens. But when your face is DOWN, the video would stop by sending "PLAY_AND_PAUSE key" via BLE.
As same when you up your face, the video restart.


2. Hand Interface

**Imagin if you can controll your PCs with your motion.**
This project make you feel in the Sci-Fi World.

You can control 
the **slides** with your **"Handsnap"**
the **screen** with your **"Hand Motion"**

Like these your hands would be Left-Hand-Devices.

3. Handy Keyboards



/*
  mode1 = presentation
  mode2 = browsing
  mode3 = media
  mode4 = individual-keys

  mode1>Btn1>IMU = arrow        <141~144>   "slide <-/->"
       >Btn2>IMU = alt+tab      <151~154>   "window cange"
       >Btn1>Btn2= play/pause   <131>       "media play/pause"
  
  mode2>Btn1>IMU = arrow*5      <241~244>   "scroll"
       >Btn2>IMU = alt+arrow    <251~254>   "go/back"
       >Btn1>Btn2= F5           <231>       "reload"
  
  mode3>Btn1>IMU = media-<>⋀⋁   <341~344>   "next/previouse/Fullscreen/unFullscreen"
       >Btu2>IMU = volume-Dn/Up <351~354> 
       >Btn1>Btn2= play/pause   <331>

  mode4>Btn1>IMU = mouse?
       >Btn2>IMU = click? scroll?
       >Btn1>Btn2= anykey       <431>       "you can choose from assets"

    assets = "arrow","PgUp/PgDn","Enter","F5","Play/Pause","next/previous","alt + arrow","alt + tab","ctrl + z/ctrl + shift + z","Fullscreen/unFullscreen"
*/
/*
  mode0 = Phone

  mode0>Btn1>IMU = mouse?
       >Btn2>IMU = scroll?
       >Btn1>Btn2= shutter?

  + grove joystick mouse??
  
*/