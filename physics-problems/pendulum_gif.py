import numpy as np 
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd

# read in the pendulum data 
df = pd.read_csv('pendulum_data.csv')

# Extract time, x, and y positions
time = df['time']
x = df['x']
y = df['y']

# Set up the figure, the axis, and the plot elements
fig, ax = plt.subplots()
ax.set_xlim(-1.1, 1.1)
ax.set_ylim(-1.1, 1.1)
ax.set_aspect('equal')

line, = ax.plot([], [], 'o-', lw=2)

# Initialization function: plot the background of each frame
def init():
    line.set_data([], [])
    return line,

# Animation function: this is called sequentially
def animate(i):
    line.set_data([0, x[i]], [0, y[i]])
    return line,

# Call the animator
anim = animation.FuncAnimation(fig, animate, init_func=init, frames=len(time), interval=20, blit=True)

# Save the animation as an MP4 file (optional)
anim.save('pendulum_animation.mp4', fps=30, extra_args=['-vcodec', 'libx264'])

# Display the animation
plt.show()


