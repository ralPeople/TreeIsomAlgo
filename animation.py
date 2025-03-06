from distutils.file_util import move_file
from multiprocessing.dummy import Array
from stringprep import b1_set
from tkinter import CENTER
from manim import *
import math
import networkx as nx
import random
class rodion_vector():
    
        #vector_values = []
        #vector_boxes = []
        #vector_tex = []
        #object_group = VGroup()
        def __init__(self, inputArray, scale = 1.0):
            self.vector_values = inputArray
            self.vector_boxes = []
            self.vector_tex = []
            self.object_group = VGroup()
            ii = 0
            for number in inputArray:
                self.vector_boxes.append(Square(1 * scale).move_to(ii * RIGHT * scale))
                t = str("$" + str(number) + "$")
                self.vector_tex.append(Tex(t).move_to(self.vector_boxes[ii].get_center()))
                self.object_group.add(self.vector_boxes[ii], self.vector_tex[ii])
                ii += 1
        def getGroup(self):
            return self.object_group
        def getArrayElement(self, id):
            if(id < 0 or id > len(self.vector_tex)):
                raise ValueError('element out of arrays range!')
            return self.vector_tex[id]
        def getArrayBox(self, id):
            if(id < 0 or id > len(self.vector_boxes)):
                raise ValueError('element out of arrays range!')
            return self.vector_boxes[id]
        def getArrayValue(self, id):
            if(id < 0 or id > len(self.vector_values)):
                raise ValueError('element out of arrays range!')
            return self.vector_values[id]
        def setArrayValue(self, val, id):
            if(id < 0 or id > len(self.vector_values)):
                raise ValueError('element out of arrays range!')
            self.object_group.remove(self.vector_tex[id])
            self.vector_values[id] = val
            t = Tex("$" + str(val) + "$").move_to(self.vector_boxes[id].get_center())
            self.vector_tex[id] = t
            self.object_group.add(self.vector_tex[id])
class Dfs():
    def __init__(self, n, e):
        self.n = n
        self.e = e
        self.q = [0] * (n+1)
        self.labels = [0] * (n+1)
        self.text = [0] * (n+1)
        self.labels_group = VGroup()
        return
    def count_q(self, x, p):
        self.q[x] = 1
        for y in self.e[x]:
            if(y == p):
                continue
            self.count_q(y, x)
            self.q[x] += self.q[y]
        return
    def write_q(self, x, p, name_dict, Tree, scene):
        scene.play(Tree.vertices[x].animate(run_time = 0.5).set_color(RED))
        for y in self.e[x]:
            if(y == p):
                continue
            self.write_q(y, x, name_dict, Tree, scene)
        self.text[x] = str(name_dict[x])
        label = Tex(name_dict[x]).scale(0.5).next_to(Tree.vertices[x], LEFT)
        self.labels[x]=label
        self.labels_group.add(label)
        scene.play(Write(label))
        scene.play(Tree.vertices[x].animate(run_time = 0.5).set_color(WHITE))
        return
    def write_polynomials(self, x, p, name_dict, positions, Tree, scene):
        kids = []
        for y in self.e[x]:
            if(y == p):
                continue
            self.write_polynomials(y, x, name_dict, positions, Tree, scene)
            kids.append(self.labels[y])
        text = ""
        if(len(kids) > 0):
            for y in kids:
                text += "("
                text += y.get_tex_string()
                text += ")"
            print(text)
            label = MathTex(text + "+X_{" + str(self.q[x])+"}").scale(0.5).next_to(Tree.vertices[x], positions[x])
        else:
            if(len(kids) == 0):
                label = MathTex(str(1) + "+X_{" + str(self.q[x])+"}").scale(0.5).next_to(Tree.vertices[x], positions[x])
            else:
                text = kids[0].get_tex_string()
                label = MathTex(text + "+X_{" + str(self.q[x])+"}").scale(0.5).next_to(Tree.vertices[x], positions[x])
        scene.play(Transform(self.labels[x], label, run_time=1))
        #scene.play(FadeOut(self.labels[x],run_time=0.0))
        self.labels[x] = label
        self.labels_group.add(self.labels[x])
        self.labels_group.add(label)
        return
    def count_hash(self, x, p, MOD, X, positions, Tree, scene):
        scene.play(Tree.vertices[x].animate(run_time = 0.5).set_color(RED))
        val = 1
        kids = []
        for y in self.e[x]:
            if(y == p):
                continue
            w = self.count_hash(y, x, MOD, X, positions, Tree, scene)
            kids.append(w)
            val *= w
        text = ""
        if(len(kids)==0):
            kids.append(1)
        for y in kids:
            if(len(text)):
                text += "\cdot"
            text += str(y)
        text += "+ " + str(X[self.q[x]])
        self.text[x] = text
        val += X[self.q[x]]
        val %= MOD
        label = MathTex(self.text[x]).scale(0.5).next_to(Tree.vertices[x], positions[x])
        scene.play(Write(label, run_time=0.5))
        scene.wait(1)
        scene.play(FadeOut(label, run_time=0.5))
        
        label = Tex(str(val)).scale(0.5).next_to(Tree.vertices[x], positions[x])
        self.labels[x]=label
        self.labels_group.add(label)
        scene.play(Write(label, run_time=0.5))
        scene.play(Tree.vertices[x].animate(run_time = 0.5).set_color(WHITE))
        return val
class Hash(Scene):
    def construct(self):
        G = nx.Graph()
        #n = 13
        #edges = [[1,2],[1,3],[3,4],[3,5],[1,6],[6,7],[6,8],[8,9],[9,10],[9,11],[8,12],[8,13]]
        n = 6
        edges = [[1,2],[1,3],[3,4],[3,5],[1,6]]
        e = [[] for i in range(n+1)]
        for i in range(1,n+1):
            G.add_node(i)
        for i in range(len(edges)):
            x,y = edges[i]
            G.add_edge(x,y)
            e[x].append(y)
            e[y].append(x)
        Tree = Graph(list(G.nodes),list(G.edges), layout="tree",root_vertex=1, layout_scale = 4.0, vertex_config={"radius" : 0.2})
        self.play(Create(Tree))
        self.wait(3)
        dfs = Dfs(n, e)
        dfs.count_q(1, -1)
        nodes = [1,2,3,4,5,6,7,8,9,10,11,12,13]
        positions = [0, LEFT, LEFT, LEFT, LEFT, LEFT, LEFT, LEFT, LEFT, RIGHT, LEFT, LEFT, LEFT, LEFT]
        names = []
        for i in range(1,n+1):
            names.append(dfs.q[i])
        name_dict = {i: label for i, label in zip(nodes, names)}
        print(name_dict)

        formula_q = Tex("$\sum q_y + 1$").to_corner(UL)
        formula_h = Tex("$\prod h_y + X_{q_x}$").next_to(formula_q, DOWN)
        self.play(Write(formula_q))
        self.wait(1)

        dfs.write_q(1, -1, name_dict, Tree, self)
        self.wait(5)
        self.play(Write(formula_h))
        self.wait(1)
        dfs.write_polynomials(1, -1, name_dict, positions, Tree, self)
        self.wait(5)
        self.play(FadeOut(formula_q), FadeOut(formula_h))
        self.wait(1)
        to_fade = dfs.labels_group
        self.play(FadeOut(to_fade,run_time=2.0))
        self.wait(2)

        t = set()
        for i in range(1, n + 1):
            t.add(dfs.q[i])
        text = "["
        for val in t:
            if(len(text)>1):
                text += ","
            text += "X_{" + str(val) +"}" 
        text += "]"
        formula_X = MathTex(text).to_corner(UL)
        self.play(Write(formula_X))
        self.wait(3)
        MOD = 1009
        tex_prime = Tex("Modulo equals $"+str(MOD)+"$").next_to(formula_X, DOWN)
        self.play(Write(tex_prime))
        self.wait(1.5)
        X = [-1] * (dfs.n+1)
        for val in t:
            print(val)
            X[val] = random.randint(2,MOD-1);
            text2 = "["
            for val2 in t:
                if(len(text2)>1):
                    text2 += ","
                if(X[val2] == -1):
                    text2 += "X_{" + str(val2) +"}"    
                else:
                    text2 += str(X[val2])
            text2 += "]"
            formula2 = MathTex(text2).to_corner(UL)
            self.play(Transform(formula_X, formula2))
            #self.wait(1.5)

        dfs.count_hash(1, -1, MOD, X, positions, Tree, self)
        self.wait(5)
        #for i in range(1,n+1):
            #label = Tex(name_dict[i]).scale(0.5).next_to(Tree.vertices[i])
            #self.play(Write(label))
        
    
