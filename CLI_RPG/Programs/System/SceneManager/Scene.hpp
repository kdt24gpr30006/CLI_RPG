#pragma once

// シーンの基底クラス
class Scene {
public:
	Scene() = default;
	~Scene() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;
};