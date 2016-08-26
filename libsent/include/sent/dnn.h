/*
 * Copyright (c) 1991-2016 Kawahara Lab., Kyoto University
 * Copyright (c) 2000-2005 Shikano Lab., Nara Institute of Science and Technology
 * Copyright (c) 2005-2016 Julius project team, Nagoya Institute of Technology
 * All rights reserved
 */

#ifndef __SENT_DNN_H__
#define __SENT_DNN_H__

#include <sent/stddefs.h>
#include <sent/htk_hmm.h>
#include <sent/htk_param.h>
#include <sent/hmm_calc.h>

typedef struct {
  float *w;			/* w [out * in]*/
  float *b;			/* b [out] */
  int in;
  int out;
} DNNLayer;

typedef struct {
  DNNLayer o;			/* output layer */
  DNNLayer *h;			/* hidden layer */
  int hnum;			/* number of hidden layers */

  float *state_prior;		/* state priors [id] */
  int state_prior_num;		/* num of above (= output layer length) */
  float prior_factor;		/* prior factor */

  int batch_size;		/* batch size */
  
  int veclen;		  /* input vector length (before expansion) */
  int contextlen;	  /* context length */
  
  int inputnodenum;		/* input layer node number */
  int hiddennodenum;		/* hidden layer node number */
  int outputnodenum;		/* output layer node number */

  float *invec;
  float *work[2];
  
} DNNData;

#endif /* __SENT_DNN_H__ */
