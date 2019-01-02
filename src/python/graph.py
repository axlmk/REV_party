import networkx as nx
from networkx.algorithms import tournament
import numpy as np
import matplotlib.pyplot as plt
import pylab

G = nx.DiGraph()

G.add_edges_from([(0, 1)], weight=85)
G.add_edges_from([(0, 2)], weight=96)
G.add_edges_from([(1, 2)], weight=73)
G.add_edges_from([(0, 3)], weight=88)
G.add_edges_from([(1, 3)], weight=66)
G.add_edges_from([(3, 2)], weight=77)
G.add_edges_from([(0, 4)], weight=85)
G.add_edges_from([(1, 4)], weight=64)
G.add_edges_from([(4, 2)], weight=71)
G.add_edges_from([(3, 4)], weight=73)
G.add_edges_from([(0, 5)], weight=91)
G.add_edges_from([(1, 5)], weight=67)
G.add_edges_from([(5, 2)], weight=66)
G.add_edges_from([(3, 5)], weight=73)
G.add_edges_from([(4, 5)], weight=67)
G.add_edges_from([(0, 6)], weight=90)
G.add_edges_from([(1, 6)], weight=63)
G.add_edges_from([(6, 2)], weight=70)
G.add_edges_from([(3, 6)], weight=73)
G.add_edges_from([(4, 6)], weight=62)
G.add_edges_from([(5, 6)], weight=62)
G.add_edges_from([(0, 7)], weight=68)
G.add_edges_from([(7, 1)], weight=77)
G.add_edges_from([(7, 2)], weight=86)
G.add_edges_from([(7, 3)], weight=73)
G.add_edges_from([(7, 4)], weight=71)
G.add_edges_from([(7, 5)], weight=74)
G.add_edges_from([(7, 6)], weight=77)
G.add_edges_from([(0, 8)], weight=90)
G.add_edges_from([(8, 1)], weight=65)
G.add_edges_from([(8, 2)], weight=78)
G.add_edges_from([(3, 8)], weight=65)
G.add_edges_from([(8, 4)], weight=69)
G.add_edges_from([(8, 5)], weight=66)
G.add_edges_from([(6, 8)], weight=69)
G.add_edges_from([(7, 8)], weight=79)
G.add_edges_from([(0, 9)], weight=92)
G.add_edges_from([(1, 9)], weight=78)
G.add_edges_from([(2, 9)], weight=74)
G.add_edges_from([(3, 9)], weight=92)
G.add_edges_from([(4, 9)], weight=89)
G.add_edges_from([(5, 9)], weight=72)
G.add_edges_from([(6, 9)], weight=86)
G.add_edges_from([(7, 9)], weight=94)
G.add_edges_from([(8, 9)], weight=86)

G.add_edges_from([(0,1)], weight=102)
G.add_edges_from([(2,1)], weight=101)

print(tournament.is_tournament(G))

edge_labels=dict([((u,v,),d['weight'])
                 for u,v,d in G.edges(data=True)])

pos=nx.circular_layout(G)
nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
nx.draw_networkx(G,pos, node_size=200)
pylab.show()