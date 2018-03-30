import cv2
import numpy as np
 
im = cv2.imread('rit.pgm')
im = im/255.0
im_power_law_transformation = cv2.pow(im,0.6)
cv2.imshow('Original Image',im)
cv2.imshow('Power Law Transformation',im_power_law_transformation)
cv2.waitKey(0)

