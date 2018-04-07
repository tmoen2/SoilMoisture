# SoilMoisture
Arduino library to read soil moisture content call action bases on value 


Function "soilRead" reads an analog signal that is based on the moisture content of the soil
  0 >> Dry
  ~500 >> Wet

Function "action" compairs value of SoilRead with one that is set by user and determines what to do.
  it is initialized to turn on and off LED's
