#ifndef gp_InstanceLearner_c
#define gp_InstanceLearner_c

#include "..\..\Include\InstanceLearner\gp_InstanceLearner.h"
#include "..\..\Include\InputGesture\gp_InputGesture.h"


/*
gpInt gpInstanceLearner_classify(gpInt, gpInt, gpFloat[])
{
	ArrayList<Prediction> predictions = new ArrayList<Prediction>();
	ArrayList<Instance> instances = getInstances();
	int count = instances.size();
	TreeMap<String, Double> label2score = new TreeMap<String, Double>();
	for (int i = 0; i < count; i++) {
		Instance sample = instances.get(i);
		if (sample.vector.length != vector.length) {
			continue;
		}
		double distance;
		if (sequenceType == GestureStore.SEQUENCE_SENSITIVE) {
			distance = GestureUtils.minimumCosineDistance(sample.vector, vector, orientationType);
		} else {
			distance = GestureUtils.squaredEuclideanDistance(sample.vector, vector);
		}
		double weight;
		if (distance == 0) {
			weight = Double.MAX_VALUE;
		} else {
			weight = 1 / distance;
		}
		Double score = label2score.get(sample.label);
		if (score == null || weight > score) {
			label2score.put(sample.label, weight);
		}
	}

//        double sum = 0;
	for (String name : label2score.keySet()) {
		double score = label2score.get(name);
//            sum += score;
		predictions.add(new Prediction(name, score));
	}

	// normalize
//        for (Prediction prediction : predictions) {
//            prediction.score /= sum;
//        }

	Collections.sort(predictions, sComparator);

	return predictions;
}
	*/

#endif
