
"""
Created 01.02.2021

source of cars Cascade
https://gist.github.com/199995/37e1e0af2bf8965e8058a9dfa3285bc6 
 
@author: rafal

program that is counting "car" objects crossing the green line
"""

import cv2 as cv

cap = cv.VideoCapture('auta3.mp4')
counter = 0

def getCenter(x, y, w, h):
    x1 = int(w / 2)
    y1 = int(h / 2)
    cx = x + x1
    cy = y + y1
    
    return (cx, cy)

while True:
    ret, frame = cap.read()
    
    cascade = cv.CascadeClassifier('cars.xml') 
    
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    cv.imshow('video2', gray)
    cars = cascade.detectMultiScale(gray, 1.1, 1)
    
    matches = []
    for (x, y, w, h) in cars:
        validation = (w >= 100) and (h >= 100)
        
        if not validation:
            continue
        
        center = getCenter(x, y, w, h)
        matches.append(center)
       
        # for vizualization
        cv.rectangle(frame, (x, y), (x + w, y + h), (0), 2)
        cv.circle(frame, center, 5, (255, 255, 0), -1)
    
    for (x, y) in matches:
        if y < 410 and y > 390:
            print(matches)
            counter += 1
            print(counter)
            
    cv.line(frame, (0, 400), (3000, 400), (0, 255, 0), 3)
    cv.putText(frame, "Auta zliczone: " + str(counter), (10, 50), cv.FONT_ITALIC, 1, (0, 0, 0), 2)
    cv.imshow('video', frame)

    if cv.waitKey(1) == 27:
        break

cv.destroyAllWindows()
