import pygame
from maze import *
from algos import *
from const import *
import argparse

def main(algo:str):
    your_name = 'TienTai'
    pygame.init() 
    pygame.display.set_caption(f'{your_name} - {algo}')
    sc = pygame.display.set_mode(RES)
    clock = pygame.time.Clock()
    sc.fill(pygame.color.Color(GREY))

    g = SearchSpace()
    g.draw(sc)
    clock.tick(200)

    if algo == 'DFS':
        DFS(g, sc)
    elif algo == 'BFS':
        BFS(g, sc)
    elif algo == 'Dijkstra':
        Dijkstra(g,sc)
    elif algo == 'AStar':
        Astar(g,sc)
    else:   
        raise NotImplementedError('Not implemented')
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit()

if __name__=='__main__':
    parser = argparse.ArgumentParser(description='Search algorithms')
    parser.add_argument('--algo', type=str, help='Enter search algorithm', default='AStar')
    args = parser.parse_args()
    main(args.algo)
