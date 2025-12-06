#pragma once
#include <memory>
#include "../Singleton/Singleton.hpp"	// シングルトンヘッダー
#include "Scene.hpp"

// シーン管理するクラス
// シングルトンを継承してシングルトンにしてます。
class SceneManager : public Singleton<SceneManager> {
	// 継承してする場合 friend class にすることで
	// private や protectedメンバ変数にアクセスできるようにする
	friend class Singleton<SceneManager>;
private:
	std::unique_ptr<Scene> currentScene;	// 現在のシーン
	std::unique_ptr<Scene> nextScene;		// 次のシーン
public:
	// シーンの変更
	template <typename T, typename... Args>
	void ChangeScene(Args&&... args) {
		// std::forward テンプレート関数の引数を元の値カテゴリを保ったまま別の関数に渡す
		nextScene = std::make_unique<T>(std::forward<Args>(args)...);
	}
	void Update();
	void Render();
};

