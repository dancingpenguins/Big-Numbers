#include "pch.h"
#include <D3DGraphics/D3Cube.h>

D3Cube getBoundingBox(LPD3DXMESH mesh) {
  LPDIRECT3DVERTEXBUFFER vertexBuffer;
  V(mesh->GetVertexBuffer(&vertexBuffer));
  return getBoundingBox(vertexBuffer);
}
