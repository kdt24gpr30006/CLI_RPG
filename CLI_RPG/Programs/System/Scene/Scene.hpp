#pragma once
// シーンの基底クラス

class Scene {
public:
	Scene();
	~Scene();
	virtual void Update();
	virtual void Render();
};