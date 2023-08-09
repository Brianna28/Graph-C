#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <raylib.h>
#include "graph.h"

void draw_graph(const Graph *graph) {
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Graph Display");
    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)){
            break;
        }
        BeginTextureMode(target);
        ClearBackground(RAYWHITE);

        for (size_t i = 0; i < graph->size; ++i) {
            float angle = (float)i / (float)graph->size * 360.0f;
            float x = screenWidth / 2 + cosf(DEG2RAD * angle) * 200;
            float y = screenHeight / 2 - sinf(DEG2RAD * angle) * 200;
            DrawCircle(x, y, 20, BLUE);

            // Draw edges
            for (size_t j = 0; j < graph->size; ++j) {
                if (graph->data[i * graph->size + j] != 0 && i != j) {
                    float x2 = screenWidth / 2 + cosf(DEG2RAD * ((float)j / (float)graph->size * 360.0f)) * 200;
                    float y2 = screenHeight / 2 - sinf(DEG2RAD * ((float)j / (float)graph->size * 360.0f)) * 200;
                    DrawLine(x, y, x2, y2, DARKBLUE);
                }
            }
        }
        EndTextureMode();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw nodes
        DrawTexturePro(target.texture,
                       (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height },
                       (Rectangle){ 0, 0, (float)screenWidth, (float)screenHeight },
                       (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
    UnloadRenderTexture(target);
    CloseWindow();
    }
#if 0
int main() {
    size_t size = 3; // Change this to the desired size of your graph
    Graph graph = new_graph(size);
    int array[3][3] = {{0,1,1},
                       {1,0,0},
                       {1,0,0}};
    init_graph_from_array(graph, array);
    // Initialize adjacency matrix data (example)
    // Note: You should populate your adjacency matrix data accordingly
    // For this example, we'll assume a fully connected graph

    draw_graph(&graph);

    free(graph.data);

    return 0;
}
#endif