import pygame
import random
import numpy as np
from robot import Robot

length,height = 400, 400 

window = pygame.display.set_mode((length,height))
clock = pygame.time.Clock()

robot = Robot(length/2, height/2, 0, 5, 5,length,height)

run = True

while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
            
    window.fill((255, 255, 255)) #fills screen with white color before every updation
    robot.move()
    robot.draw(window)
    pygame.display.flip() #This will update the contents of the entire display
    clock.tick(100) #frame is updated 100 times ina second
    
pygame.quit()