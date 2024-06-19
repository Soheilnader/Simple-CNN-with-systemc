# Very simple Convolutional neural network (CNN) for image recognition with SystemC
For this assignment, our goal is to create a module that can search for specific patterns in input images. This module is called the Pattern Finder Circuit and it is made up of three convolutional blocks, each with 3x3 kernels. The purpose of each convolutional block is to search for a particular pattern in a 4x4 input image. After each convolutional block, there is a ReLU activation function followed by a 2x2 Max Pool layer.

![Figure 1: Schematic of the circuit](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/pattern_finder.png?raw=true "Figure 1: Schematic of the circuit")

## Introduction
The first step in image processing involves passing the input image through a convolutional layer. This layer applies filters to the image to extract features like shapes. Sometimes, the output of this stage passes through an activation function like the ReLU. Figure 2 shows the result of applying ReLU to a sample matrix. In Figure 3, we can see the convolutional process in action with a kernel size of 3 and a stride of 1.





