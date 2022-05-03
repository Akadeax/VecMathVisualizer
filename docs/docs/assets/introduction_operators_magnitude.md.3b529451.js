import{_ as n,c as s,o as a,d as p}from"./app.2ed2a9a6.js";const b='{"title":"Magnitude","description":"","frontmatter":{},"headers":[],"relativePath":"introduction/operators/magnitude.md","lastUpdated":1651606220000}',e={},t=p(`<h1 id="magnitude" tabindex="-1">Magnitude <a class="header-anchor" href="#magnitude" aria-hidden="true">#</a></h1><p>The magnitude operation is defined for 1D, 2D, 3D vectors and quaternions:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> a <span class="token operator">=</span> <span class="token number">5.0</span>
vecmath<span class="token operator">&gt;</span> ma <span class="token operator">=</span> <span class="token operator">|</span>a<span class="token operator">|</span>
vecmath<span class="token operator">&gt;</span> print ma
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>The (logical) output is:</p><div class="language-cpp line-numbers-mode"><pre><code>ma <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">5</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br></div></div><p>For a 2d vector:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">5</span><span class="token punctuation">,</span><span class="token number">12</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> mb <span class="token operator">=</span> <span class="token operator">|</span>b<span class="token operator">|</span>
vecmath<span class="token operator">&gt;</span> print mb
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>the output is:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> mb <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">13</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br></div></div><p>For a 3d vector:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> c <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3</span><span class="token punctuation">,</span><span class="token number">8</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">2</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> mc <span class="token operator">=</span> <span class="token operator">|</span>c<span class="token operator">|</span>
vecmath<span class="token operator">&gt;</span> print mc
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>the output is:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> mc <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">8.77496</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br></div></div><p>For a quaternion:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> q <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3</span><span class="token punctuation">,</span><span class="token punctuation">(</span><span class="token number">1</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">2</span><span class="token punctuation">,</span><span class="token number">4</span><span class="token punctuation">)</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> mq <span class="token operator">=</span> <span class="token operator">|</span>q<span class="token operator">|</span>
vecmath<span class="token operator">&gt;</span> print mq
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>the output is:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> mq <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">5.47723</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br></div></div>`,17),o=[t];function r(c,l,i,u,m,d){return a(),s("div",null,o)}var v=n(e,[["render",r]]);export{b as __pageData,v as default};
