#include "clvpch.h"
#include "LayerStack.h"
#include "Layer.h"

namespace clv{
	LayerStack::~LayerStack(){
		CLV_TRACE("Deconstructing layer stack...");
		for(auto layer : layers){
			layer->onDetach();
			CLV_INFO("{0} detached", layer->getName());
		}
	}

	void LayerStack::pushLayer(std::shared_ptr<Layer> layer){
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		CLV_TRACE("Attached layer: {0}", layer->getName());
		layer->onAttach();
	}

	void LayerStack::popLayer(std::shared_ptr<Layer> layer){
		auto it = std::find(layers.begin(), layers.end(), layer);
		if(it != layers.end()){
			layers.erase(it);
			--layerInsertIndex;
			CLV_TRACE("Popped layer: {0}", (*it)->getName());
			(*it)->onDetach();
		}
	}

	void LayerStack::pushOverlay(std::shared_ptr<Layer> overlay){
		overlay->onAttach();
		CLV_TRACE("Attached overlay: {0}", overlay->getName());
		layers.emplace_back(std::move(overlay));
	}

	void LayerStack::popOverlay(std::shared_ptr<Layer> overlay){
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if(it != layers.end()){
			layers.erase(it);
			CLV_TRACE("Popped overlay: {0}", (*it)->getName());
			(*it)->onDetach();
		}
	}
}