import numpy as np
import random
import pygame

class Robot:
    def __init__(self, x, y,direction, size,speed,length,height):
        self.x = x
        self.y = y
        self.size = size
        self.direction=direction
        self.speed=speed
        self.length=length
        self.height=height
        
    def rotate(self):
        rotation_duration = np.random.uniform(0, 2 * np.pi)
        self.direction += rotation_duration

    def move(self):
        while True:
           self.x += self.speed * np.cos(self.direction)
           self.y += self.speed * np.sin(self.direction)

           if self.x <= 0 or self.x >= self.length or self.y <= 0 or self.y >= self.height:
               self.rotate()
           else:
               break
            
    def draw(self, window):
        pygame.draw.circle(window, (255, 0,0), (self.x, self.y), self.size)
        # arguments are as: circle(surface, color, center, radius)