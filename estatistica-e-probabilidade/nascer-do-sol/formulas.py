from math import (
    sin,
    cos,
    tan,
    acos,
    radians,
    degrees,
)

from datetime import (
    timedelta,
)

def earth_declination(n):
    return 23.45 * sin(radians(360/365 * (284+n)))

def td(lat):
    dec = earth_declination(119) #TODO Change this literal
    cofactor = -(tan(radians(lat)) * tan(radians(dec)))
    return 2/15 * degrees(acos(cofactor))

def longitude_correction(lng, fuse):
    diff = lng - fuse
    
    return timedelta(
        minutes=(diff * 60) / 15
    )

def day_range(td, lng, fuse):
    td /= 2
    sunrise = timedelta(hours=12-td)
    sunset = timedelta(hours=12+td)

    correction = longitude_correction(lng, fuse)
    sunrise += correction
    sunset += correction
    
    return (sunrise, sunset)

lat = -23.543333
lng = 46.633056
fuse = 45

td = td(lat)
sunrise, sunset = day_range(td, lng, fuse)
