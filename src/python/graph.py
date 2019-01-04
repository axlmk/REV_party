import networkx as nx
from networkx.algorithms import tournament
import numpy as np
import matplotlib.pyplot as plt
import pylab

G = nx.DiGraph()

G.add_edges_from([(0, 2)], weight=9)
G.add_edges_from([(3, 1)], weight=6)
G.add_edges_from([(3, 2)], weight=6)
G.add_edges_from([(1, 0)], weight=1)
G.add_edges_from([(1, 2)], weight=0)


print(tournament.is_tournament(G))

edge_labels=dict([((u,v,),d['weight'])
                 for u,v,d in G.edges(data=True)])

pos=nx.circular_layout(G)
nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
nx.draw_networkx(G,pos, node_size=200)
pylab.show()
