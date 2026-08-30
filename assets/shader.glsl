@vs vs
in vec4 position;
in vec4 color;

out vec4 vert_color;

void main() {
    gl_Position = position;
    vert_color = color;
}
@end

@fs fs
in vec4 vert_color;
out vec4 frag_color;

void main() {
    frag_color = vert_color;
}
@end

@program triangle vs fs