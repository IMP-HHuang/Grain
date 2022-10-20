#include <TCanvas.h>
#include<TROOT.h>
#include<TGraphErrors.h>
#include<TF1.h>
#include<TLegend.h>
#include<TLatex.h>

using namespace std;

//int main()
void fit()
{
	const Int_t n_points = 16;
	Double_t channel__vals[n_points] = {67.0871, 71.8580, 101.599, 135.946, 239.181, 265.817, 288.045, 322.881, 332.752, 356.172, 406.687, 688.195, 843.839, 946.224, 968.224, 1217.04};
	Double_t channel_errs[n_points] = {0.000515, 0.000996, 0.00035, 0.00028, 0.00057, 0.00066, 0.00042, 0.00033, 0.00024, 0.00066, 0.00107, 0.00067, 0.00071, 0.00095, 0.00081, 0.00076};
//	Double_t channel_sigam[n_points] = {0.9464, 0.718, 0.685, 0.791, 0.802, 0.724, 0.720, 0.701, 0.792, 0.884, 0.825, 0.890, 0.947};
	Double_t Energy_vals[n_points] = {39.91, 45.7, 81.0, 121.78, 244.70, 276.4, 302.9, 344.28, 356.0, 383.8, 443.96, 778.90, 964.08, 1085.9, 1112.1, 1408.0};
//	Double_t Energy_vals_FWHM[n_points] = {81.0, 121.78, 244.70, 276.4, 302.9, 344.28, 356.0, 383.8, 443.96, 778.90, 964.08, 1085.9, 1112.1    , 1408.0};
	Double_t Energy_errs[n_points] = {0};
//	Double_t Energy_residual[n_points] = {0.0551, -0.0697, 0.0116, 0.088, -0.004, -0.02, -0.071, -0.003, 0.024, 0.086, 0.029, 0.006, -0.003, -0.04, -0.04, 0.05};
//	Double_t Energy_FWHM[n_points] = {1.662625, 1.716675, 1.81937, 1.84945, 1.836525, 1.894335, 1.906085, 1.92794, 1.98387, 2.27715, 2.342715, 2.502045, 2.478075, 2.71589};
//	Double_t Energy_FWHM_errs[n_points] = {0.001685, 0.001203, 0.002578, 0.003191, 0.002148, 0.001774, 0.001307, 0.003598, 0.005769, 0.004733, 0.004808, 0.006425, 0.00239, 0.004919};


	TGraphErrors graph(n_points, channel__vals, Energy_vals, channel_errs, Energy_errs);   //nullptr
//	graph.SetTitle("Energy Calibtation Residual; Energy [KeV]; Residual [KeV]");
	graph.SetTitle("Energy Calibration; Channel; Energy [KeV]");
	graph.SetMarkerStyle(20);   //20
	graph.SetMarkerColor(3);
	graph.SetLineColor(3);
	auto mycanvas = new TCanvas("Fit","Fit");
//	mycanvas->cd();
	graph.DrawClone("APE");  //APE
//	graph.Fit("pol2");
//	mycanvas->cd();
//	TLatex text(1.8, 200, "#splitline{p0 = 1.60282 +/- 0.016941)}{p1 = 0.000870895 +/- 6.34346e-05}{p1 = -6.05489e-08 +/- 4.35081e-08}");

	TLatex *text = new TLatex(1.0, 1.0,"#splitline{p0 = -39.8912 +/- 0.0339727}{p1 = 1.18984 +/- 0.0001546}");
	TLatex *text1 = new TLatex(1.0, 2.0,"p2 = -1.04223e-07 +/- 1.26086e-07");
//	text->SetTextAlign(12);
//	text->SetTextFont(13);
//	text->SetTextColor(3);
//	text->SetTextSize(20);
//	text->SetTextAngle(0);
	mycanvas->cd();
	text->DrawClone();
	text1->DrawClone();

/*
	TLatex text;
	text.SetTextSize(0.08);
	text.SetTextAlign(23);
	mycanvas->cd();
	text.DrawLatex(0.1, 0.2, "hhhhhhhhhhhhhhhhh");
*/
/*
	TF1 f("Linear law", "[0]*x^2+[1]*x+[2]", .0,  1500.);
	TF1 f("Linear law", "[0]*x+[1]", .0,  1500.);
	f.SetLineColor(3);
	f.SetLineStyle(1);
	graph.Fit(&f);
	f.DrawClone("Same");
*/
}
