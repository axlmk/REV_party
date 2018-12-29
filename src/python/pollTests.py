import networkx as nx
from networkx.algorithms import tournament
import numpy as np
import matplotlib.pyplot as plt
import pylab

G = nx.DiGraph()

# ajouter les arcs ici
G.add_edges_from([(0,1)], weight=102)
G.add_edges_from([(2,1)], weight=101)

print(tournament.is_tournament(G))

edge_labels=dict([((u,v,),d['weight'])
                 for u,v,d in G.edges(data=True)])

pos=nx.circular_layout(G)
nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
nx.draw_networkx(G,pos, node_size=200)
pylab.show()
